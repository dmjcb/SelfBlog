<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2021-12-07 00:19:50
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-07 02:04:04
-->

# Hexo

## 安装

- 修改npm源

```sh
sudo npm install gitbook-cli -g --registry=http://registry.npm.taobao.org 
```

```sh
# 新建目录
sudo npm install -g hexo-cli

# 初始化
hexo init

# 安装 hexo 依赖包
sudo npm install

# 阅读时间统计功能
sudo npm install hexo-wordcount --save

# 字数统计功能
sudo npm install hexo-wordcount --save
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211207224409.png)

## 启动

### 生成静态网站

```sh
hexo g
```

### 启动服务器

```sh
hexo s
```

```sh
hexo g && hexo s
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2021-12-07_23-10-56.jpg)

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211207231203.jpg)

### 修改主题

```sh
# 根目录下执行
git clone https://github.com/liuyib/hexo-theme-stun.git themes/stun

# 安装依赖 hexo-renderer-pug
sudo npm install --save hexo-renderer-pug
```

### 建立文章

```sh
hexo new [layout] <title>
```

| 参数 | 描述                                                    |
| ---- | ------------------------------------------------------- |
| -p   | --path    自定义新文章的路径                            |
| -r   | --replace    如果存在同名文章, 将其替换                 |
| -s   | --slug    文章的 Slug, 作为新文章的文件名和发布后的 URL |

```sh
hexo new page --path about/hello "Hello World"
```

创建 source/about/hello.md 文件, 同时 Front Matter 中的 title 为 "Hello World"


### 远程推送

#### _config.yml修改
  
```xml
deploy:
  type: git
  repo: git@github.com:xxx/xxx.github.io.git
  branch: main
```

#### 推送插件

```sh
sudo npm install hexo-deployer-git --save
```

- d 表示部署在远端

```sh
hexo g && hexo d
```

## 问题

### Math渲染

- 更换Hexo的markdown渲染引擎

```sh
npm uninstall hexo-renderer-marked --save

npm install hexo-renderer-kramed --save
```

- 修改node_modules\kramed\lib\rules\inline.js文件

```sh
sudo vim node_modules\kramed\lib\rules\inline.js
```

```js
// escape: /^\\([\\`*{}\[\]()#$+\-.!_>])/, 
escape: /^\\([`*\[\]()#$+\-.!_>])/, 
...
//  em: /^\b_((?:__|[\s\S])+?)_\b|^\*((?:\*\*|[\s\S])+?)\*(?!\*)/, 
  em: /^\*((?:\*\*|[\s\S])+?)\*(?!\*)/, 
```

- 在主题中开启mathjax开关

主题的_config.yml

```yml
math:
  enable: true
  per_page: true
  engine: mathjax
```

- 在文章的Front-matter里打开mathjax开关

```m
---
...
mathjax: true
--
```

### 综合问题

- hexo not found

```py
echo "export PATH=$PATH:/opt/node-v16.13.1-linux-x64/lib/node_modules/hexo-cli/bin" >> ~/.bashrc

source ~/.bashrc
```

- 1

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2021-12-07_23-04-41.jpg)

- 将nodejs升级到高于12.0.0的版本

- _config.xml中的 highlight->enable的值修改为false

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/2021-12-07_23-09-48.jpg)

- 2

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211208001031.png)

```sh
sudo cnpm install --save hexo-renderer-jade hexo-generator-feed hexo-generator-sitemap hexo-browsersync hexo-generator-archive