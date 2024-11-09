import os
import shutil
import codecs
import sys
import subprocess

class AutoUploadBlog:
    __ROOT_DIR        = "c:\\Users\\dmjcb\\Documents\\Code"

    __BLOG_DIR        = "{0}\\SelfBlog".format(__ROOT_DIR)
    __JEYLL_DIR       = "{0}\\dmjcb.github.io".format(__ROOT_DIR)

    __RESOURCE_DIR    = "Resource"

    def del_unused_images(self):
        def __extract_file_name(path):
            f = '\\'
            if '/' in path:
                f = '/'
            return path.split(f)[-1]

        def __get_files_ap(dir_path):
            files = []
            for path, dirs, fs in os.walk(dir_path):
                if ".git" in path:
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
                        name = __extract_file_name(line[:-1])
                        imgs.append(name)
            return imgs

        # 提取md中已使用图片URL
        used_imgs = ["head.jpg", "workbench.jpg"]
        for f in __get_files_ap(self.__BLOG_DIR):
            if "md" == f[-2:]:              
                urls = __extract_imgurs_url(f)
                used_imgs.extend(urls)

        # 删除未使用图片
        imgur_dir  = "{0}\\{1}\\Imgur".format(self.__BLOG_DIR, self.__RESOURCE_DIR)
        img_count = 0
        del_count = 0
        for ap in __get_files_ap(imgur_dir):
            img_count += 1
            name = __extract_file_name(ap)
            if name not in used_imgs:
                del_count += 1
                os.remove(ap)
                print('del: ', name)
        
        # 有新增
        if img_count > len(used_imgs):
            return img_count - len(used_imgs)
        # 有删除
        if del_count > 0:
            return -1 * del_count
        
        return 0


    def run_cmd(self, command):
        r = subprocess.run(command, shell=True, capture_output=True, text=True, encoding="utf8")
        print(r.stdout)
    
    
    def upload_blog(self):
        msg = sys.argv[1]
        count = self.del_unused_images()
        if count != 0:
            msg += ";update {0} imgs".format(count)
        print(msg)
        os.chdir(self.__BLOG_DIR)
        self.run_cmd("git add . && git commit -m {0} && git push".format(msg))


    def upload_jekyll(self):
        SOURRC_DIR = "{0}\\_posts\\{1}\\Imgur".format(self.__JEYLL_DIR, self.__RESOURCE_DIR)
        TARGET_DIR = "{0}\\{1}\\Imgur".format(self.__JEYLL_DIR, self.__RESOURCE_DIR)

        def _pull_blog(self):
            os.chdir("{0}\\_posts".format(self.__JEYLL_DIR))
            self.run_cmd("git pull")

        def _push(self):
            os.chdir(self.__JEYLL_DIR)
            self.run_cmd("git add . && git commit -m {0} && git push".format(sys.argv[1]))

        def copy_with_ignore_git(src_dir, dst_dir):
            # 检查目标目录是否存在，如果存在则先删除它
            if os.path.exists(dst_dir):
                shutil.rmtree(dst_dir)

            # 定义忽略函数，忽略 ".git" 文件夹
            def ignore_git(dir, files):
                return [".git"] if ".git" in files else []

            # 复制目录，并忽略 ".git" 文件夹
            shutil.copytree(src_dir, dst_dir, ignore=ignore_git, dirs_exist_ok=True)

        self._pull_blog()
        copy_with_ignore_git(SOURRC_DIR, TARGET_DIR)
        self._push()

if __name__ == "__main__":
    auto = AutoUploadBlog()
    auto.upload_blog()
    # auto.upload_jekyll()