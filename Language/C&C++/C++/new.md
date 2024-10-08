<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2024-09-21 21:03:49
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-28 13:41:15
-->

# new

## 概念

new 是 C++ 中的关键字, 用来分配内存并构造对象的操作符

new 是高层次操作, 隐藏了底层的内存分配细节

```c++
T *p = new T();
```

```mermaid
graph LR;
    A(new特点)
    A-->B(同时进行内存分配和对象构造)
    A-->C(若内存分配失败, 抛出 std::bad_alloc 异常)
    A-->D(可用于单个对象或数组创建)
```

### operator new 函数

operator new 是可重载函数, 只负责内存分配(类似于malloc 函数), 不调用构造函数

```c++
void* operator new(std::size_t size) {
    std::cout << "Custom operator new called!" << std::endl;
    // 调用全局的 operator new 分配内存
    return ::operator new(size);  
}
```

operator new 只负责从自由存储区(堆)中分配足够的内存, 不关心内存中存储的数据, 也不调用构造函数

```mermaid
graph LR;
    A(operator new特点)
    A-->B(只负责内存分配, 不初始化对象)
    A-->C(可重载以自定义内存分配过程)
    A-->D(若分配失败也抛出 std::bad_alloc 异常, 除非使用 nothrow 版本)
```

#### 重载

重载 operator new 可以让我们在内存分配时添加一些额外的逻辑 

- 内存池管理: 通过自定义 operator new, 你可以实现内存池来减少动态内存分配的开销

- 调试: 你可以在 operator new 中记录日志, 跟踪每次内存分配的调用

- 性能优化: 对于特定类型的对象, 可以通过自定义的 operator new 来优化内存分配策略

- 异常处理: 你可以自定义 operator new 来处理分配失败时的异常, 甚至返回 nullptr 而不是抛出异常

### ::operator new

全局的 operator new, 用于分配内存

- 与 operator new 的区别

(1) ::operator new 强制调用全局作用域的 operator new, 即标准库提供的默认版本

(2) operator new 则可能是全局的, 也可能是你自己在某个类中定义的重载版本


### 区别

操作符/函数	|作用|是否调用构造函数|是否抛出异常
| --------------------------- | ---------------- |---------|-----------|
new|	分配内存并构造对象|是|是(如果内存分配失败)
operator new |只分配内存, 不构造对象, 允许类自定义内存分配策略	|否|	是(如果内存分配失败)
::operator new	|全局的 operator new, 只分配内存, 调用默认的内存分配实现|	否	|是(如果内存分配失败)

## 流程

### 分配内存

new 关键字调用 operator new 默认从堆(自由存储区)中分配内存来存储对象

(1) operator new 如果内存分配失败, 会抛出 std::bad_alloc 异常(而不像 malloc 返回 NULL)

(2) 若有自定义 operator new, 则会优先调用, 否则调用全局的 ::operator new

```c++
void* operator new(std::size_t size) {
    // 分配 size 大小的内存
    void* p = ::malloc(size);
    // 内存分配失败时抛出异常
    if (!p) {
        throw std::bad_alloc();
    }
    return p;
}
```

### 初始化对象

分配内存后, new 操作符会在刚分配的内存上调用对象构造函数, 进行初始化

(1) 定位 new (placement new) 构造函数会使用定位 new, 即在已经分配的内存位置上构造对象

(2) 对象的构造函数会根据传入的参数初始化对象的成员变量和状态

```c++
// 在已经分配好的内存 ptr 上调用构造函数
T* obj = new(ptr) T();  
```

这个操作本质上是通过“定位 new”机制, 确保构造函数在分配的内存地址上正确执行


### 处理异常

在内存分配和对象构造的过程中, 可能会发生异常

尤其是在构造函数中, 如果某些资源(如文件、网络连接等)无法正确初始化时, 会抛出异常

new 操作符需要处理确保内存泄漏不发生

(1) 如果内存分配失败：operator new 会抛出 std::bad_alloc 异常

(2) 如果构造函数抛出异常：会释放已经分配的内存, 并传播异常, C++ 通过 RAII异常处理机制, 确保不会泄漏资源

```c++
// 1. 分配内存
T* obj = static_cast<T*>(operator new(sizeof(T)));

try {
    // 2. 定位 new, 调用构造函数
    new (obj) T();  
} catch (...) {
    // 3. 构造失败, 释放内存
    operator delete(obj);
    // 4. 重新抛出异常  
    throw; 
}
```

### 返回指针

最后, 若内存分配和对象构造都成功, new 操作符返回指向已初始化对象的指针, 此时对象已经完全初始化, 可正常使用

```c++
#include <iostream>

class ExampleUseNew {
public:
    ExampleUseNew() {
        std::cout << "Constructor called" << std::endl;
    }

    ~ExampleUseNew() {
        std::cout << "Destructor called" << std::endl;
    }

    // 重载 operator new
    void* operator new(std::size_t size) {
        std::cout << "Custom operator new called, size: " << size << std::endl;
        // 调用全局的 operator new
        return ::operator new(size);  
    }

    // 重载 operator delete
    void operator delete(void* p) {
        std::cout << "Custom operator delete called" << std::endl;
        // 调用全局的 operator delete
        ::operator delete(p); 
    }
};

int main() {
    ExampleUseNew* obj = new ExampleUseNew();
    delete obj;

    return 0;
}
```

运行结果

```c
Custom operator new called, size: 1
Constructor called
Destructor called
Custom operator delete called
```