<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2024-09-23 16:08:45
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-23 20:30:28
-->

> [NASM汇编初探(入门教程)](https://blog.csdn.net/qq_52300431/article/details/127397862)

> [搭建i386交叉编译环境](https://github.com/lordmilko/i686-elf-tools)

# ASM

## 程序

```asm
section .data
    msg db 'Hello World!', 0AH     ; 初始化变量msg
 
section .text
    global  _start
 
_start:
    mov	edx, 13     ; 待写入的字节数(每个字母一个字节, 再加上换行符0Ah)
    mov ecx, msg    ; 将msg的内存地址移入ecx
    mov ebx, 1      ; 表示写入到标准输出STDOUT
    mov eax, 4      ; 调用SYS_WRITE(OPCODE是4)
    int 0x80

    mov ebx, 0
    mov eax, 1
    int 0x80
```

此时生成的32位目标文件

```sh
nasm -f elf Hello.asm
```

- 链接

```sh
ld -m elf_i386 Hello.o -o Hello

或

gcc -m32 -c Hello.o -o Hello
```