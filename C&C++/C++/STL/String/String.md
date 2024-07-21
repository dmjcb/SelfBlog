<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:  
 * @Date: 2022-01-13 12:21:39
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-21 21:37:28
-->

# String

## c_str

```c
const char* c_str() const
```

返回一个指向正规C字符串的指针常量, 内容与本string串相同

## 函数

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
    int sum = 0;
    std::string s1;
    std::string s2;

    std::cin >> s1 >> s2;
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