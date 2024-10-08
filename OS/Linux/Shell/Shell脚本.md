<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-10-10 00:15:19
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-10-10 01:58:44
-->

# Shell

- `#!`

约定标记, 告诉系统脚本需要什么解释器执行

```sh
#!/bin/bash
```

- 赋予脚本权限

```sh
sudo chmod +x 脚本.sh
```

## 变量

```sh
变量名=值
```

```sh
a=123
```

- 只读变量
  
```sh
readonly 变量名
```

## 使用

```sh
${变量名}
```

```sh
a=123

echo ${a}
```

## 字符串

### 单引号

```sh
s='this is a string'
```

单引号里的变量无效, 任何字符都会原样输出

单引号字符串中不能出现单独一个的单引号(对单引号使用转义符后也不行), 但可成对出现, 作为字符串拼接使用

### 双引号

```sh
n="runoob"

s="Hello, I know you are "${n}""
```

双引号字符串中可出现变量

### 函数

- 获取字符串长度
  
```sh
${#字符串}
```

```sh
s="abcdefg"
# 7
${#s}
```

- 从index下标截取n个字符
  
```sh
${字符串:index:n}
```

```sh
s="abcdefg"

# cde
${s:2:3}
```

- 字符转换

| 函数         | 作用                     |
| ------------ | ----------------------- |
| ${字符串, }  | 首字符换成小写            |
| ${字符串,, } | 所有大写字母全部替换为小写 |
| ${字符串^}   | 首字符换成大写            |
| ${字符串^^}  | 所有小写字母全部替换为大写 |

- 判断字符串是否空

```sh
# 1.直接判断
if ! ${n};then
...
fi

# 2.test命令判断
if test -z "${n}";then
...
fi

# 3.空判断
if "${n}" = "";then
...
fi
```

## 数组

数组用括号表示, 元素用空格分割

### 数组定义

- 括号定义

```sh
array=(元素1 元素2 ...)
```

- 下标定义

```sh
array[0]=v1
array[1]=v2
...
```

### 读取

- 单个读取
  
```sh
${array[下标]}
```

```sh
a=(1 2 3 4 5)

# 1
${a[0]}

# 3
${a[2]}
```

- 全部获取

```sh
${array[*]} 或 ${array[@]}
```

```sh
a=(1 2 3 4 5)

# 1 2 3 4 5
${a[*]}
```

### 函数

- 获取长度

```sh
${#array[*]} 或  ${#array[@]}
```

```sh
a=(1 2 3 4 5)

# 5
${#a[*]}
```

## {}与()

`()`将命令置于子Shell中执行

`{}`将命令在同哥Shell内完成

获取VLC的pid, 关闭VLC

```sh
#!/bin/bash

pid=${ps -aux | grep vlc | grep -v grep | awk '{print $2}'}

if ! "${pid}";then
    sudo kill -9 ${pid}
fi
```


## 脚本

配置定时任务

```sh
#!/bin/bash

# 每小时第mintue分钟执行任务
read -p "输入分钟(00‐59):" mintue
# 每天第hour小时执行任务
read -p "输入小时(00‐24):" hour
# 每月第date天执行任务
read -p "输入日期(01‐31):" date
# 每年第month月执行任务
read -p "输入月份(01‐12):" month
# 每周第weak天执行任务
read -p "输入星期(00‐06):" weak
read -p "输入计划任务的命令或脚本:" program
# 追加命令至/etc/crontab文件中
echo "$mintue $hour $date $month $weak $program" >> /etc/crontab
```

创建文件

```sh
#!/bin/bash

read -p "输入文件路径与文件名:" path
if ! -f "${path}";then
    touch ${path}
else
    
fi
```

## 并发

Shell不支持多线程, 只能采用多进程的方式, 即在并发指令后加`&`

```sh
#!/bin/bash

for i in {1..5};do
    # 将命令转入后台执行
    echo ${i} &
done

# 多线程同步
wait
echo "end"
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211229172645.png)

```sh
#!/bin/bash

# 并发建立3个docker busy_box容器

for i in {1..3};do
    docker run -itd --name box_${i} busybox /bin/sh &
done

wait
```

查询当前网段下所有主机

```sh
#!/bin/bash

for i in {1..254};do
    ip="192.168.43.${i}"
    # 将标准/错误输出全部重定向到/dev/null中(将产生的所有信息丢弃)
    ping -c 2 ${ip} > /dev/null && echo ${ip} is up &
done

wait
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211229173115.png)