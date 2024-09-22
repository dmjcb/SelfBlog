<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2021-12-30 22:01:01
 * @LastEditors: dmjcb
 * @LastEditTime: 2023-04-23 09:30:55
-->

# Flask打包

## 方法一

```sh
pyinstaller -F -i --add-data="./static;./static" --add-data="./templates;./templates"  app.py
```

dist 目录下会生成可执行文件

## 方法二

- 安装

```sh
pip install pyinstaller -i https://pypi.doubanio.com/simple
```

- 打包

```sh
pyinstaller -F app.py
```

- 复制文件

将static 与templates 目录复制到dist目录下

- 修改.spec

```sh
datas=[('./static', 'static'), ('./templates', 'templates')], 
```

- 打包

```sh
pyinstaller -F *.spec
```

![](/.imgur/20211230223519.png)

## 参考

[Python-web Flask框架项目打包成exe文件](https://www.cxyzjd.com/article/qq_42370335/114276385)  

[Flask项目能打包为单个exe文件运行？掌握原理后居然如此简单!](https://bbs.huaweicloud.com/blogs/210229)