<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-11-27 20:45:27
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-10-10 00:10:55
-->

# string函数

```c
#include<string.h>
```

## strcmp

```c
int strcmp(const char *s1, const char *s2)
```

- 若 s1 == s2, 返回值 0

- 若 s1 < s2, 返回值小于 0

- 若 s1 > s2, 返回值大于 0

## strstr

```c
char *strstr(const char *s1, const char *s2)
```

查找 s2在s1中首次出现的位置, 返回第一次出现s2的位置, 若未找到则返回NULL

```c
const char haystack[20] = "RUNOOB";
const char needle[10] = "NOOB";
char *ret;

// NOOB
ret = strstr(haystack, needle);
```

## strcat

```c
char *strcat(char *dest, const char *src)
```

把 src 所指向的字符串追加到 dest 所指向的字符串的结尾

```c
char src[50], dest[50];

strcpy(src, "AAAA");
strcpy(dest, "BBBB");

strcat(dest, src);

// BBBBAAAA
printf("%s\n", dest);
```

## strcpy

```c
char *strcpy(char *dest, const char *src)
```

把 src 所指向的字符串复制到 dest

```c
char a[7] = "abcdef";
char b[4] = "ABC";

strcpy(a, b);

// ABC
printf("%s\n", a);
```

## strncpy

```c
char *strncpy(char *dest, const char *src, size_t n)
```

把 src 所指向的字符串复制到 dest, 最多复制 n 个字符. 当 src 的长度小于 n 时, dest 的剩余部分将用空字节填充

## memset

```c
void *memset(void *str, int c, size_t n)
```

复制字符 c(一个无符号字符)到参数 str 所指向字符串的前 n 个字符

| 参数 | 含义                   |
| ---- | ---------------------- |
| str  | 指向要填充的内存块     |
| c    | 要被设置的值           |
| n    | 要被设置为该值的字符数 |

```c
int a[10];

// 给数组a赋值0
memest(a, 0, sizeof(a));
```
