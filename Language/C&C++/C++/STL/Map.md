<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2021-08-18 16:22:55
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-23 14:27:14
-->

# Map

## 定义

```c++
template <class Key, class Value>
std::map<Key, Value> m;
```

## 插入

```c++
m.insert(make_pair(key, value))
```

## 添加

```c++
m[key] = value
```

## 取值

```c++
m[key]
```

## 遍历

```c++
// 方法1
for(auto it = m.begin(); it != m.end(); it++) {
    // it->first, it->second;
}

// 方法2
for (auto &[k, v] : m) {
    // k, v
}
```

```c
#include <iostream>
#include <map>

int main(void) {
    std::map<std::string, int32_t> m = { {"Wang", 20}, {"Li", 22}, {"Deng", 19} };

    for (auto &[k, v] : m) {
        std::cout << k << ", " << v << std::endl;
    }
}
```

## 查询

查找 key 是否存在, 若iterator 指向end() 即不存在

```c++
std::map<T, V>::iteraotr it;

it.find(key)
```

## 删除

删除键为 key 的键值对

```c++
template <class T, class V>
std::map<T, V> m;

m.erase(key)
```
