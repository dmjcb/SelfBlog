<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2022-01-13 12:21:39
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-23 14:28:38
-->

# String

## 接口

### c_str

```c
const char* c_str() const
```

返回一个指向正规C字符串的指针常量, 内容与本string串相同

### getline

输入一行可含空格的str

```c
std::string str;

getline(std::cin, str);
```

### find

```c++
#include<iostream>
#include<string>

int main() {
    std::string s1 = "abcdef";
    std::string s2 = "abc";

    int sum = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1.find(s2, i) != std::string::npos){
            sum++;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
```

### erase

```c++
#include<iostream>
#include<string>

int main() {
    std::string s = " 123 456237";

    int index = 3;
    int length = 1;
    s.erase(index, length);

    std::cout << s << std::endl;
    return 0;
}
```