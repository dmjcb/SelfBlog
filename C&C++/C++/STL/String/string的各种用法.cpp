/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2024-07-06 20:33:50
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-06 20:42:04
 */
#include <iostream>
#include <cstdio>
#include <string>

int main(void)
{

    std::string s1;

    std::string s3 = "Ich liebe dich!";
    std::string s4(10, 'a');
    std::string s5(s4);
    std::string s6 = std::string(6, 'c');
    std::string s7 = s3 + s4;
    std::string s8 = "";

    getline(std::cin, s1);
    std::string s2 = s1;
    int size = s3.size();

    std::string s10 = s2 + ", ";
    std::string s11 = s1 + "hello " + ", ";

    std::cout << "s1:" << s1 << std::endl;
    std::cout << "s2:" << s2 << std::endl;
    std::cout << "s3:" << s3 << " " << size << std::endl;
    std::cout << "s4:" << s4 << std::endl;
    std::cout << "s5:" << s5 << std::endl;
    std::cout << "s6:" << s6 << std::endl;
    std::cout << "s7:" << s7 << std::endl;
    std::cout << s8.empty() ? "s8 is empty string" : "NO";
    std::cout << "s10:" << s10 << std::endl;
    ;
    std::cout << "s11:" << s11 << std::endl;
}
