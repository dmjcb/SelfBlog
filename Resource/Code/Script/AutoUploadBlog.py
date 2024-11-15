import os
import shutil
import codecs
import sys
import subprocess
from datetime import datetime

class AutoGit:
    def run_cmd(self, command):
        r = subprocess.run(command, shell=True, capture_output=True, text=True, encoding="utf8")
        print(r.stdout)
        return r.stdout
    
    def pull(self, path):
        os.chdir(path)
        self.run_cmd("git pull")

    def push(self, path, msg):
        os.chdir(path)
        self.run_cmd("git add . && git commit -m {0} && git push".format(msg))
    
    def status(self, path):
        os.chdir(path)
        r =  self.run_cmd("git status {0}".format(path))
        if "Your branch is up to date" in r and "nothing to commit, working tree clean" in r:
            return True
        return False


class AutoUploadBlog:
    _ROOT            = "c:\\Users\\dmjcb\\Documents\\Code"
    _BLOG            = "{0}\\SelfBlog".format(_ROOT)
    _JEKYLL          = "{0}\\dmjcb.github.io".format(_ROOT)
    _IMGUR           = "{0}\\Imgur".format(_ROOT)

    _RESOURCE_IMGUR  = "Resource\\Imgur"
    _PUBLIC_BLOG     = "Resource\\PublicBlog"

    _URL             = "https://dmjcb.github.io"

    auto_git = AutoGit()

    def get_root_path(self):
        absolute_path = os.path.abspath(__file__)
        x = absolute_path
        for i in range(5):
            x = os.path.dirname(x)
        return x
        

    def del_unused_images(self):
        def __extract_file_name(path):
            f = '\\'
            if '/' in path:
                f = '/'
            return path.split(f)[-1]

        def __get_files_ap(dir_path):
            files = []
            for path, dirs, fs in os.walk(dir_path):
                if ".git" in path or "PublicBlog" in path:
                    continue
                for f in fs:
                    ap = os.path.join(path, f)
                    files.append(ap)
            return files

        def __extract_imgurs_url(md_file):
            imgs = []
            with codecs.open(md_file, "rb", "utf-8", errors="ignore") as text:
                for line in text:
                    line = line.replace("\r\n", "")
                    # example: ![](/Resource/Imgur/20241022204809.png)
                    if "/Resource/Imgur/" in line:
                        name = __extract_file_name(line.strip()[:-1])
                        imgs.append(name)
            return imgs

        # 提取md中已使用图片URL
        used_imgs = ["head.jpg", "workbench.jpg"]
        for f in __get_files_ap(self._BLOG):
            if "md" == f[-2:]:              
                urls = __extract_imgurs_url(f)
                used_imgs.extend(urls)

        # 删除未使用图片
        img_count = 0
        del_count = 0
        dirs  = "{0}\\{1}".format(self._BLOG, self._RESOURCE_IMGUR)
        for ap in __get_files_ap(dirs):
            img_count += 1
            name = __extract_file_name(ap)
            if name not in used_imgs:
                print('name = ', name)
                del_count += 1
                os.remove(ap)
        
        if img_count > len(used_imgs):
            return img_count - len(used_imgs)

        if del_count > 0:
            return -1 * del_count
        
        return 0

    # 上传图床
    def upload_imgur(self):
        print("更新 Imgur")
        def delete_files_in_directory(directory):
            for root, dirs, files in os.walk(directory, topdown=True):
                # 排除 .git 目录及其子目录
                if '.git' in dirs:
                    dirs.remove('.git')

                for file in files:
                    file_path = os.path.join(root, file)
                    try:
                        os.remove(file_path)
                    except Exception as e:
                        print(f"删除文件 {file_path} 时发生错误: {e}")
                    
        # 删除Imgur下文件
        delete_files_in_directory(self._IMGUR)

        # 从Blog中拷贝最新图片
        src_dir = "{0}\\{1}".format(self._BLOG, self._RESOURCE_IMGUR)
        shutil.copytree(src_dir, self._IMGUR, dirs_exist_ok=True)

        msg = "update imgs"
        self.auto_git.push(self._IMGUR, msg)


    def upload_blog(self, msg):
        print("更新SelfBlog项目")
        count = self.del_unused_images()

        # 若Resource/Imgur 有更新, 同步更新Imgur项目
        if self.auto_git.status("{0}//{1}".format(self._BLOG, self._RESOURCE_IMGUR)) is False:
            self.upload_imgur()
        
        self.auto_git.push(self._BLOG, msg)


    def upload_jekyll(self, msg):
        print("更新dmjcb.github.io项目")
        def copy_with_ignore_git(src_dir, dst_dir):
            if os.path.exists(dst_dir):
                shutil.rmtree(dst_dir)

            # 忽略函数，忽略 ".git" 文件夹
            def ignore_git(dir, files):
                return [".git"] if ".git" in files else []

            shutil.copytree(src_dir, dst_dir, ignore=ignore_git, dirs_exist_ok=True)
        
        self.auto_git.pull("{0}\\_posts".format(self._JEKYLL))

        src_dir = "{0}\\_posts\\{1}".format(self._JEKYLL, self._RESOURCE_IMGUR)
        tar_dir = "{0}\\{1}".format(self._JEKYLL, self._RESOURCE_IMGUR)
        copy_with_ignore_git(src_dir, tar_dir)

        self.auto_git.push(self._JEKYLL, msg)

    # 将博客转换为发布模式
    def change_md_to_public(self, md_name):
        # 获取原文地址
        def get_original_address(categories, file_name):
            x = categories.replace("/r", "").replace("/n", "").replace(" ", "").split(":")[-1]
            x = x[1:-2].lower().split(',')
            
            y = ''
            for i in x:
                y = '{0}/{1}'.format(y, i)

            title = file_name.split('-')[-1]
            title = title[:-3]

            url = "{0}{1}/{2}".format(self._URL, y, title)
            return url

        # 根据文件名查找绝对地址
        def find_file_in_directory(md_name):
            for root, dirs, files in os.walk(self._BLOG):
                if md_name in files:
                    return os.path.abspath(os.path.join(root, md_name))
            return None

        def get_md_content(md_name):
            path = find_file_in_directory(md_name)
            if path == None:
                return

            with open(path, 'r', encoding='utf-8') as f:
                x = f.readlines()
            return x

        lines = get_md_content(md_name)
        origin_url = get_original_address(lines[3], md_name)
        new_text = ['> - [**dmjcb个人博客**](https://dmjcb.github.io/)\n', '> - [原文地址]({0})\n'.format(origin_url)]
        for i, text in enumerate(lines):
            if i < 7:
                continue

            if text == '```c++\n' or text == '```cmake\n':
                text = '```c\n'
            
            if text == '```sh\n':
                text = '```shell\n'

            if '/Resource/Imgur' in text:
                text = text.replace('/Resource/Imgur', 'https://raw.githubusercontent.com/dmjcb/Imgur/main')

            new_text.append(text)

        title = lines[1].replace("/r", "").replace("/n", "").split(":")[-1]
        path = "{0}\\{1}\\{2}.md".format(self._BLOG, self._PUBLIC_BLOG, title[2:-2])
        with open(path, 'w', encoding='utf-8') as f:
            f.writelines(new_text)
    
    def create_new_blog(self, name):        
        date = datetime.now().strftime("%Y-%m-%d")
        file_name = "{0}-{1}.md".format(date, name)

        lines = [
            "---\n",
            'title: "{0}"\n'.format(name),
            "date: {0}\n".format(datetime.now().strftime("%Y-%m-%d")),
            "categories: []\n",
            "tags: []\n",
            'excerpt: "{0}"\n'.format(name),
            "---\n"
        ]

        with open(file_name, "w") as f:
            f.writelines(lines)


if __name__ == "__main__":
    auto = AutoUploadBlog()
    print(auto.get_root_path())

    index = input('1. 删除无用图片\n2. 上传blog\n3. 上传jekyll\n4. 都上传\n5. 转换博客为发行格式\n6. 创建新博客\n')
    index = int(index)
    if index == 1:
        r = auto.del_unused_images()
        print(r)
    elif index == 2:
        msg = input('commit info: ')
        auto.upload_blog(msg)
    elif index == 3:
        msg = input('commit info: ')
        auto.upload_jekyll(msg)
    elif index == 4:
        msg = input('commit info: ')
        auto.upload_blog(msg)
        auto.upload_jekyll(msg)
    elif index == 5:
        path = input('name: ')
        auto.change_md_to_public(path)
    elif index == 6:
        name = input('name: ')
        auto.create_new_blog(name)