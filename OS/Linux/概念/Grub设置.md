<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-08-17 00:11:16
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-28 21:57:15
-->

# GRUB

GRUB(GRand unified bootloader)是多操作系统启动程序, 用来引导不同系统, 如Windows、Linux

GRUB可用于选择操作系统分区上的不同内核, 也可用于向这些内核传递启动参数

Linux常见的引导程序包括LILO、GRUB、GRUB2

## 双系统修复

```sh
sudo gedit /etc/default/grub
```

修改内容如下

```sh
GRUB_TIMEOUT_STYLE="false"
```

- 更新

```sh
sudo grub-mkconfig -o /boot/grub/grub.cfg
```

## Ubuntu

### 多硬盘启动

图形化管理工具 grub-customizer

```sh
sudo add-apt-repository ppa:danielrichter2007/grub-customizer

sudo apt-get install -y grub-customizer
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20210817002414.png)

### 美化引导页面

下载主题包, 编辑/etc/default/grub添加

```sh
GRUB_THEME="/主题包路径/theme.txt"

# echo GRUB_THEME="/主题包路径/theme.txt" >> /etc/default/grub
```

更新grub

```sh
sudo update-grub
```
