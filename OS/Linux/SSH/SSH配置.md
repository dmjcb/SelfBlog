<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-03-14 13:31:07
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-10-10 02:00:20
-->

# SSH

## 命令

### 连接

```sh
ssh 用户名@IP地址 (-p 端口号)
```

连接192.168.1.1的dmjcb用户, 端口号默认为20

```sh
ssh dmjcb@192.168.1.1
```

### 清除密钥

```sh
ssh-keygen -R [远程主机IP]
```

### 免密登录

- 手动复制密钥

将本地`id_rsa.pub` 复制到远程主机`.ssh/authorized_keys`里

- 命令复制密钥

```sh
ssh-copy-id -i ~/.ssh/id_rsa.pub [远程用户]@[远程主机IP]
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211229213337.png)

## SSH配置

### .ssh目录

在根目录(/root/或者/home/用户名)下生成 .ssh目录

```sh
ssh-keygen -t rsa
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20210312104415.png)

```mermaid
graph LR;
    s(.ssh目录)

    s1(authorized_keys)
    s2(id_rsa)
    s3(id_rsa.pub)
    s4(know_hosts)

    s11(存储其他主机公钥)
    s21(本机私钥)
    s31(本机公钥)
    s41(存储已认证主机host key)

    s-->s1
    s-->s2
    s-->s3
    s-->s4

    s1-->s11
    s2-->s21
    s3-->s31
    s4-->s41

```

### 配置文件

```sh
/etc/ssh/sshd_condfig
```

```sh
# 允许密钥登录
RSAAuthentication yes

# 允许公钥验证 
PubkeyAuthentication yes

# 禁止密码登录
PasswordAuthentication no
```

## 工具

### 获取登录信息

/etc/ssh/目录下新建sshrc

```sh
#!/bin/bash

# 获取登录者的用户名
user=${USER}

# 获取登录者的IP地址
ip=${SSH_CLIENT%% *}

# 获取登录的时间
time=${date +%F%t%k:%M}

# 服务器的IP地址
server=${ifconfig wlp2s0 | sed -n '2p' | awk '{print $2}'}

echo ${user} ${ip} ${time} ${server}
```

### Web工具

> [https://github.com/huashengdun/webssh](https://github.com/huashengdun/webssh)

```sh
pip3 install webssh
```

- 直接运行wssh, 默认8888端口

```sh
wssh
```

- 绑定IP地址端口

```sh
wssh --address='IP地址' --port=端口
```