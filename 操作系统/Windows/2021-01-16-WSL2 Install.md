---
title: "操作系统-Windows-WSL2 Install"
date: 2021-01-16
categories: [操作系统]
tags: [操作系统]
excerpt: "WSL2 Install"
---

# WSL2

## 启用 Linux 子系统

打开 控制面板 -> 程序 -> 启用或关闭 $Windows$ 功能.找到"适用于 $Linux$ 的 $Windows$ 子系统"和"虚拟机平台", 勾选这两项, 并重新启动计算机.

## 切换到 WSL2

使用管理员用户打开 $CMD$, 运行:

```sh
wsl --set-default-version 2
```

## 添加 Docker 源

```sh
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

sudo add-apt-repository "deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu $(lsb_release -cs) stable"

sudo apt update
```

## 安装 Docker

```sh
sudo apt install -y docker-ce
```

## 设置权限

使用 docker info 命令出现权限不足问题

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20200721210505.png)

```sh
# 添加docker用户组
sudo groupadd docker

# 将登陆用户加入到docker用户组中
sudo gpasswd -a $USER docker

# 更新用户组
newgrp docker
```

## 启动 Docker daemon

```sh
sudo service docker start
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20200721210744.png)

## 关闭

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20200721211633.png)

该进程是 WSL 的进程,比较占内存, 不使用 WSL2 的时候可关闭

```s
wsl --shutdown
```
