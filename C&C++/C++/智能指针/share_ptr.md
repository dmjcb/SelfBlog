<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2022-03-27 21:36:47
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-10 22:29:01
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

- 指向一块 10 个 int 类型数据的堆内存空间

```c
std::shared_ptr<int> p = std::make_shared<int>(10);
```

## 引用

### 查看引用数

```c
use_count()
```

```c
#include <iostream>
#include <memory>

int main()
{
    int value = 0xFF;

    std::shared_ptr<int> p = std::make_shared<int>(value);

    // 1
    std::cout << "p的引用个数:" << p.use_count() << std::endl;
}
```

## 获取指针且不增加引用数

```c
get()
```

```c
#include <iostream>
#include <memory>

int main()
{
    int value = 0xFF;
    std::shared_ptr<int> p = std::make_shared<int>(value);

    // 1
    std::cout << "p引用个数:" << p.use_count() << std::endl;
    auto x = p;
    // 2
    std::cout << "p引用个数:" << p.use_count() << std::endl;

    int value1 = 0xFF;
    std::shared_ptr<int> p1 = std::make_shared<int>(value1);
    // 1
    std::cout << "p1引用个数:" << p1.use_count() << std::endl;
    auto x1 = p1.get();
    // 1
    std::cout << "p1引用个数:" << p1.use_count() << std::endl;
}
```