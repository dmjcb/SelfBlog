/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-04-18 17:41:31
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-31 00:49:07
 */

#include <iostream>
#include <memory>

int main()
{
    int value = 0x3FF;

    std::shared_ptr<int> p = std::make_shared<int>(value);

    std::cout << "p指向值为:" << std::hex << *p << std::endl;
    std::cout << "p指针引用个数为:" << p.use_count() << std::endl;


    std::shared_ptr<int> p2(p);

    std::cout << std::hex << &value << std::endl;
    std::cout << "p2指向值为:" << *p2 << std::endl;
    std::cout << "p指针引用个数为:" << p.use_count() << std::endl;

    std::cout << std::hex << p.get() << std::endl;

    // p指针指向空, 则引用个数会自动归零
    p = nullptr;
    std::cout << "p指针引用个数为:" << p.use_count() << std::endl;
}