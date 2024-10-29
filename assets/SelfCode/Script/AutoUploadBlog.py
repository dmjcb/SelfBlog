import os
import shutil
import codecs
import sys
import subprocess

class AutoUploadBlog:
    __ROOT_DIR        = "c:\\Users\\dmjcb\\Documents\\Code"
    __IMGUR_DIR       = "assets\\SelfImgur"
    __CODE_DIR        = "assets\\SelfCode"

    __BLOG_DIR        = "{0}\\SelfBlog".format(__ROOT_DIR)
    __JEYLL_DIR       = "{0}\\dmjcb.github.io".format(__ROOT_DIR)

    __BLOG_IMGUR_DIR  = "{0}\\{1}".format(__BLOG_DIR, __IMGUR_DIR)
    __JEYLL_IMGUR_DIR = "{0}\\{1}".format(__JEYLL_DIR, __IMGUR_DIR)


    def __get_in_used_images(self):
        in_used = []
        for path, dirs, fs in os.walk(self.__BLOG_DIR):
            if ".git" in path:
                continue
            for f in fs:
                ap = os.path.join(path, f)
                if ".md" == ap[-2:]:
                    with codecs.open(ap, "rb", "utf-8", errors="ignore") as text:
                        for line in text:
                            line = line.replace("\r\n", "")
                            # example: ![](/assets/SelfImgur/20241022204809.png)
                            if "/assets/SelfImgur/" in line:
                                name = line[:-1].split('/')[-1]
                                in_used.append(name)
                
        return in_used
    
    def del_blog_unused_images(self):
        in_used = self.__get_in_used_images()
        count = 0
        for path, dirs, files in os.walk(self.__BLOG_IMGUR_DIR):
            for f in files:     
                if f not in in_used:
                    count += 1
                    ap = os.path.join(path, f)
                    os.remove(ap)

        print("1. SelfBlog SelfImgur del {0} images".format(count))


    def copy_imgur_dir(self):
        count = 0
        src_files = os.listdir(self.__BLOG_IMGUR_DIR)
        for name in src_files:
            f = os.path.join(self.__BLOG_IMGUR_DIR, name)
            if os.path.isfile(f):
                shutil.copy(f, self.__JEYLL_IMGUR_DIR)
                count += 1
        
        print("2. Copy {0} images".format(count))


    def __get_imgurs(self):
        in_used = []
        for path, dirs, files in os.walk(__BLOG_IMGUR_DIR):
            for f in files:
                path = os.path.join(path, f)
                in_used.append(f)

        return in_used


    # 删除dmjcb.github.io/assets/SelfImgur中未使用的图片
    def del_jeyll_unused_images(self):
        in_used = self.__get_imgurs()
        count = 0
        for path, dirs, files in os.walk(self.__JEYLL_IMGUR_DIR):
            for f in files:
                if f not in in_used:
                    ap = os.path.join(path, f)
                    os.remove(ap)
                    count += 1

        print("3. dmjgb.github.io SelfImgur del {0} images".format(count))


    def update_images(self):
        self.del_blog_unused_images()
        self.copy_imgur_dir()
        self.del_jeyll_unused_images()


    def git_pipline(self):
        def __run(command):
            r = subprocess.run(command, shell=True, capture_output=True, text=True, encoding="utf8")
            print(r.stdout)
            print()
        
        def __pull():
            sh = "git pull"
            __run(sh)

        def __push():
            sh = "git add . && git commit -m {0} && git push".format(sys.argv[1])
            __run(sh)
        
        print("4. run git")

        os.chdir(self.__BLOG_DIR)
        __push()

        os.chdir("{0}\\_posts".format(self.__JEYLL_DIR))
        __pull()

        os.chdir(self.__JEYLL_DIR)
        __push()


    def run(self):
        self.update_images()

        self.git_pipline()


if __name__ == "__main__":
    upload = AutoUploadBlog()
    upload.del_blog_unused_images()