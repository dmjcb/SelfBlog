<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2022-02-21 18:34:00
 * @LastEditors: dmjcb
 * @LastEditTime: 2023-04-17 15:45:08
-->

# grep

## 文本查找

```sh
grep -[参数] 匹配项
```

| 参数 | 说明                                   |
| ---- | -------------------------------------- |
| `-c` | 只输出匹配行的计数                     |
| `-i` | 匹配内容不区分大小写                   |
| `-h` | 查询多文件时不显示文件名               |
| `-l` | 查询多文件时只输出包含匹配字符的文件名 |
| `-n` | 显示匹配行及行号                       |
| `-s` | 不显示不存在或无匹配文本的错误信息     |
| `-v` | 显示不包含匹配文本的所有行             |
| `-w` | 精确匹配                               |

## 单查询

### 模糊匹配

含有匹配项的字段都会匹配

```sh
grep (模式) [匹配项]
```

```sh
# 匹配结果为abc abcd abcdef
grep "abc"
```

### 精确匹配

```sh
grep -w [匹配项]
```

```sh
# 结果为abc
grep -w "abc"
```

## 与查询

在前一个查询的结果中继续查询

```sh
grep '模式1' [匹配项] | grep '模式2'
```

- 查询3月10日16点30时间段内的ssh登录成功的情况

```sh
grep 'Mar 10 16:3' /var/log/secure | grep Accepted
```

![](/.imgur/20210310175209.png)

## 或查询

```sh
grep '模式1|模式2' [匹配项] 或 

grep -E '模式1|模式2' [匹配项]
```

## 非查询

去除包含模式1的进程行, 避免影响最终数据的正确性

```sh
grep -v 模式1 [匹配项]
```

- 查询VLC进程信息时排除grep本身影响
  
```sh
ps -aux | grep vlc | grep -v grep
```

![](/.imgur/20220221184345.png)

## 正则

### 查看以pattern开头的行

```sh
grep ^pattern
```

## 查找以pattern结尾的行

```sh
grep pattern$
```

- 查找/root/test.txt文件中含有human的句子

```sh
grep human /root/test.txt
```

![](/.imgur/20210310151418.png)

- 查找/root/test.txt文件中以The开头的句子

```sh
grep ^The /root/test.txt
```

![](/.imgur/20210310151535.png)