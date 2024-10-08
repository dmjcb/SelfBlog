<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-09-24 20:37:24
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-28 14:39:05
-->

# 文件

## 创建

```py
path = ""

f = open(path, 'w', encoding = 'utf-8')
if os.path.exists(path):
    f.close()
    return
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211225130907.png)

### 创建临时文件

tempfile.NamedTemporaryFile 函数用于创建具有特定名称的临时文件

```sh
def touch_tmp_file(request):
    id = request.GET['id']
    tmp_file = tempfile.NamedTemporaryFile(prefix=id)
    return HttpResponse(f"tmp file: {tmp_file} created!", content_type='text/plain')
```

## 修改

### 写入追加

- `'w'`写入, `'a'`追加

```py
with open(path, 'w', encoding = 'utf-8') as f:
    f.write(data)
f.close()
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211225132548.png)

### 重命名
  
```py
os.rename(old_path, new_path)
```

## 读取

```py
with open(path, 'r', encoding = 'utf-8') as f:
    # 整体读取
    data = f.read()

    # 逐行读取
    for i in f.readlines():
        ...
f.close()
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211225142026.png)

## 移动

```py
import os
import shutil

def move_file(source_path: str, target_path: str):
    # 待移动文件不存在
    if not os.path.isfile(source_path):
        return
    path, name = os.path.split(target_path)
    if not os.path.exists(path):
        os.makedirs(path)
    # 复制文件 shutil.copyfile() 
    shutil.move(source_path,  target_path)
```

## 删除


```py
def del_file(path: str):
    if not os.path.exists(path):
        return
    os.remove(path)
```

## 显示

### 显示文件

```py
def display_all_files(folder_path: str):
    for i in os.listdir(folder_path):
        path = os.path.join(folder_path, i)
        # 如果是文件则显示
        if os.path.isfile(path):
            print(path)
```

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20211225150924.png)

### 递归显示

```py
def display_all_folders(folder_path: str):
    for i in os.listdir(folder_path):
        path = os.path.join(folder_path, i)
        # 如果该对象是文件夹
        if os.path.isdir(path):
            display_all_files(path)
```

## 问题

### 路径错误

Windows路径中 `\` 会被视作转义字符, 导致路径错误

若文件路径为`C:\Users\XXX\Desktop\x.txt`, 需改为

```sh
r'C:\Users\XXX\Desktop\x.txt' 或

'C:\\Users\XXX\Desktop\\x.txt' 或

'C:/Users/XXX/Desktop/x.txt'
```