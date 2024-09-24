<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2021-03-10 11:23:08
 * @LastEditors: dmjcb
 * @LastEditTime: 2023-04-15 10:46:32
-->

# awk

## 文本分析

将文件逐行读入, 以空格为默认分隔符将每行切片, 再对切开的部分进行各种分析处理

```sh
awk [参数] '{pattern action}' {文件名}
```

| 参数    | 含义                                   |
| ------- | -------------------------------------- |
| pattern | awk 在数据中查找的内容                 |
| action  | 在找到匹配内容时执行的命令             |
| {}      | 用于根据特定的模式对一系列指令进行分组 |

- 查看登录的用户名

```sh
last -n 5 | awk '{print $1}'
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20220109114810.png)