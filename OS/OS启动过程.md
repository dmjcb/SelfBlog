<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-01-16 17:59:34
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-24 00:55:28
-->

# 计算机启动过程

> [从零开始写 OS 内核 - BIOS 启动到实模式](https://segmentfault.com/a/1190000040131294)

## 读取 BIOS

按下电源按钮后, 计算机首先读取一块存储有基本输入输出系統即 BIOS 程序的芯片

开机后 CPU 初始模式是实模式, 地址宽度为 20 位, 即最大地址空间 1MB, 其划分固定, 每一块都被映射到不同设备上

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20240923_230527.jpg)

### BIOS作用

(1) 开机后 CPU 的指令寄存器 IP 被强置为地址 0xFFFF0, 该地址被映射到 BIOS 固件上的代码, 是计算机开机后第一条指令的地址

(2) CPU 开始执行 BIOS 上的代码, 这一部分主要是硬件输入输出设备相关的检查, 以及建立一个最初的中断向量表

(3) BIOS 代码最后阶段的工作, 是检查启动盘上的 MBR 分区, 即磁盘上的第一个 512B 内容, 又叫引导分区

BIOS 会对这 512B 做一个检查, 其最后2个字节必须是0x55 和 0xaa, 否则就不是合法启动盘

(4) 检查通过后, BIOS 将这 512B 加载到内存 0x7C00 处, 到 0x7E00 为止, 然后指令跳转到 0x7C00 开始执行

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20240924_005051.jpg)

### 内存布局规划

