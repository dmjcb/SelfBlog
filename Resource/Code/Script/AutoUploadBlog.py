import os
import shutil
import codecs
import sys
import subprocess


class AutoGit:
    def run_cmd(self, command):
        r = subprocess.run(command, shell=True, capture_output=True, text=True, encoding="utf8")
        print(r.stdout)
    
    def pull(self, path):
        os.chdir(path)
        self.run_cmd("git pull")

    def push(self, path, msg):
        os.chdir(path)
        self.run_cmd("git add . && git commit -m {0} && git push".format(msg))


class AutoUploadBlog:
    __URL             = "https://dmjcb.github.io"
    __ROOT_DIR        = "c:\\Users\\dmjcb\\Documents\\Code"

    __BLOG_DIR        = "{0}\\SelfBlog".format(__ROOT_DIR)
    __JEYLL_DIR       = "{0}\\dmjcb.github.io".format(__ROOT_DIR)

    __IMGUR_DIR       = "Resource\\Imgur"

    __PUBLIC_BLOG_DIR = "Resource\\PublicBlog"

    auto_git = AutoGit()
        

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
        for f in __get_files_ap(self.__BLOG_DIR):
            if "md" == f[-2:]:              
                urls = __extract_imgurs_url(f)
                used_imgs.extend(urls)

        # 删除未使用图片
        imgur_dir  = "{0}\\{1}".format(self.__BLOG_DIR, self.__IMGUR_DIR)
        img_count = 0
        del_count = 0
        for ap in __get_files_ap(imgur_dir):
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


    def upload_blog(self, msg):
        count = self.del_unused_images()
        if count != 0:
            print("update {0} imgs".format(count))
        
        self.auto_git.push(self.__BLOG_DIR, msg)


    def upload_jekyll(self, msg):
        def copy_with_ignore_git(src_dir, dst_dir):
            if os.path.exists(dst_dir):
                shutil.rmtree(dst_dir)

            # 忽略函数，忽略 ".git" 文件夹
            def ignore_git(dir, files):
                return [".git"] if ".git" in files else []

            shutil.copytree(src_dir, dst_dir, ignore=ignore_git, dirs_exist_ok=True)
        
        SOURRC_DIR = "{0}\\_posts\\{1}".format(self.__JEYLL_DIR, self.__IMGUR_DIR)
        TARGET_DIR = "{0}\\{1}".format(self.__JEYLL_DIR, self.__IMGUR_DIR)

        self.auto_git.pull("{0}\\_posts".format(self.__JEYLL_DIR))

        copy_with_ignore_git(SOURRC_DIR, TARGET_DIR)

        self.auto_git.push(self.__JEYLL_DIR, msg)

    # 将博客转换为发布模式
    def change_md_to_public(self, md_name):
        # 获取原文地址
        def get_original_address(categories, file_name):
            categories = categories.replace("/r", "").replace("/n", "").split(":")[-1]
            categories = categories[2:-2].lower()
            title = file_name.split('-')[-1]
            title = title[:-3]

            url = "{0}/{1}/{2}".format(self.__URL, categories, title)
            return url

        # 根据文件名查找绝对地址
        def find_file_in_directory(md_name):
            for root, dirs, files in os.walk(self.__BLOG_DIR):
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
        path = "{0}\\{1}\\{2}.md".format(self.__BLOG_DIR, self.__PUBLIC_BLOG_DIR, title[2:-2])
        with open(path, 'w', encoding='utf-8') as f:
            f.writelines(new_text)


if __name__ == "__main__":
    auto = AutoUploadBlog()

    index = input('1. 删除无用图片\n2. 上传blog\n3. 上传jekyll\n4. 都上传\n5. 转换博客\n')
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
        path = input('path: ')
        auto.change_md_to_public(path)
    