<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2022-09-25 23:27:18
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-10-10 01:08:19
-->

# this

this 是 C++ 中的一个关键字, 是 const 指针

## 指向

this 指针指向当前对象, 只能用在类的内部

this 可以访问类的所有private、protected、public 属性成员

## 赋值

对象被创建后编译器自动给 this 赋值, 用户不能显式赋值

```c++
#include <iostream>

class Person {
public:
    Person(std::string name) {
        this->mName = name;
    };

    void PrintThis() {
        std::cout << "this pointer = " << std::hex << this << std::endl;
    };

private:
    std::string mName;
};

int main(void) {
    Person p{"Casper"};

    // this pointer = 0x61FEDC
    p.PrintThis();

    // p address = 0x61FEDC
    std::cout << "p address = " << std::hex << &p << std::endl;
}
```
