<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2022-07-06 20:08:07
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-24 23:05:44
-->

# Winodws设置

## MBR->GPT

```sh
# 查询所有磁盘
list disk

# 选中目标盘
select disk 需转换格式磁盘的数字编号

# 清空磁盘
clean

# 转换位gpt分区
convert gpt
```

## 系统设置

### 设置Host

```sh
C:\Windows\System32\drivers\etc\host
```

### 关闭window defener

```sh
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows Defender" /v "DisableAntiSpyware" /d 1 /t REG_DWORD /f
```

### 关闭win10搜索栏热门搜索

[win10搜索栏热门搜索](https://blog.csdn.net/onecdll/article/details/137139604)

### 关闭防火墙

regedit 打开注册表

```
计算机\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\mpsSvc
```

右边的Start 改成4