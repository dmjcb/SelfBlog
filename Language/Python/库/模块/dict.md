<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-12-02 23:02:30
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-28 14:25:43
-->

# 字典

字典是另一种可变容器模型, 且可存储任意类型对象

字典的每个键值以`:`分割, 每个键值对之间用`,`分割, 字典包括在花括号 `{}` 中

## 访问

### 键值对

```py
d = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}

# 7
d['Age']
```

```mermaid
graph LR;
    subgraph 值
        v1(Zara)
        v2(7)
        v3(First)
    end

    subgraph 键
        k1(Name)
        k2(Age)
        k3(Class)
    end

    k1-->v1
    k2-->v2
    k3-->v3
```

### 遍历

```py
# Name Zara
# Age 7      
# lass First
for k, v in d.items():
    print(k, v)
```

## 修改

```py
dict[key] = value
```

```py
d = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}

# 修改
d['Name] = 'Wang';
```

## 删除

### 删除键值

```py
del dict[key]
```

```py
d = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}

del d['Age']

# {'Name': 'Zara', 'Class': 'First'}
print(d)
```

### 清空字典所有条目

```py
dict.clear()
```

### 删除字典

```py
del dict
```

## 函数

### 内置函数

| 函数              | 描述                     |
| ----------------- | ----------------------- |
| cmp(dict1, dict2) | 比较两个字典元素          |
| len(dict)         | 计算字典元素个数          |
| str(dict)         | 输出字典可打印的字符串表示 |
| type(variable)    | 返回输入的变量类型        |

### 字典函数

| 函数                   | 描述                                        |
| ---------------------- | ------------------------------------------ |
| clear()                | 删除字典内所有元素                           |
| copy()                 | 返回一个字典的浅复制                         |
| get(key, default=None) | 返回指定键的值, 如果值不在字典中返回default值 |
| has_key(key)           | 如果键在字典dict里返回true, 否则返回fale     |
| items()                | 以列表返回可遍历的(键, 值) 元组数组          |
| keys()                 | 以列表返回一个字典所有的键                   |
| update(dict2)          | 把字典dict2的键/值对更新到dict里             |
| values()               | 以列表返回字典中的所有值                     |
| pop(key[, default])    | 删除字典给定键 key 所对应的值                |
| popitem()              | 返回并删除字典中的最后一对键和值              |

```py
d = {'name': 'Wang', 'age': 19, 'sex': 'male'}

# Wang
d.get('name', 'XXX')

# 30
d.get('height', 30)
```

## 转换

通过import json导入

| 函数    | 作用                           |
| ------- | ----------------------------- |
| loads() | 将json转化成dict               |
| dumps() | 将dict转化成json               |
| load()  | 读取json, 转成dict             |
| dump()  | 将dict转化成json后写入jsonw文件 |