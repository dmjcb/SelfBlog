<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2022-03-27 21:36:47
 * @LastEditors: dmjcb
 * @LastEditTime: 2023-06-01 22:44:41
-->

# shared_ptr

## 初始化

### 构造出空指针

```c
std::shared_ptr<T> p;
```

### 赋值初始化

```c
std::make_shared<T>
```

- 指向一块10 个 int 类型数据的堆内存空间

```c
std::shared_ptr<int> p = std::make_shared<int>(10);
```

## 引用

### 查看引用个数

```c
use_count()
```

```c
std::shared_ptr<int> p = std::make_shared<int>();

*p = 96;

// 1
p.use_count();
```

## 获取

```c
get()
```
