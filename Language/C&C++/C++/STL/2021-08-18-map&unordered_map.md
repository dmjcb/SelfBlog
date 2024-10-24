---
title: "C++-STL-map&unordered_map"
date: 2021-08-18
categories: [C&C++]
tags: [C&C++]
excerpt: "map&unordered_map"
---

# std::map & unordered_map

## map

### 定义

```c++
template <class Key, class Value>
std::map<Key, Value> m;
```

### 插入

```c++
m.insert(make_pair(key, value))
```

### 添加

```c++
m[key] = value
```

### 取值

```c++
m[key]
```

### 遍历

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

### 查询

查找 key 是否存在, 若iterator 指向end() 即不存在

```c++
std::map<T, V>::iteraotr it;

it.find(key)
```

### 删除

删除键为 key 的键值对

```c++
template <class T, class V>
std::map<T, V> m;

m.erase(key)
```

## unordered_map

std::unordered_map是一种关联容器, 提供基于哈希表的数据结构, 可快速地进行键值对插入、删除、查找操作

与std::map相比, std::unordered_map中的元素无序, 因为它使用哈希表来存储元素, 而非树结构

### 定义和初始化

```c++
// 定义一个键类型为std::string, 值类型为int的unordered_map
std::unordered_map<std::string, int> m; 
```

### 插入元素

- 使用operator[]插入或更新元素

```c++
// 插入键值对 ("apple", 2)
m["apple"] = 2;

// 插入键值对 ("banana", 3)
m["banana"] = 3;
```

- 使用insert方法插入元素

```c++
// 插入键值对 ("orange", 4)
m.insert({"orange", 4}); 
```

### 访问元素

- 使用operator[]访问元素(若键不存在, 会创建一个默认值)

```c++
// 访问键为 "apple" 的值, 输出 2
int count = m["apple"]; 
```

- 使用at方法访问元素(若键不存在, 会抛出异常)

```c++
try {
    int count = m.at("banana");
    std::cout << "banana count: " << count << std::endl;
} catch (const std::out_of_range& e) {
    std::cout << "Key not found" << std::endl;
}
```

### 查找元素

使用find方法查找元素(返回迭代器)

```c++
auto it = m.find("orange");
if (it != m.end()) {
    std::cout << "Found orange with count: " << it->second << std::endl;
} else {
    std::cout << "orange not found" << std::endl;
}
```

### 删除元素

- 使用erase方法删除指定键的元素

```c++
// 删除键为 "apple" 的元素
m.erase("apple"); 
```

- 使用clear方法删除所有元素

```c++
m.clear();
```

### 检查元素是否存在

使用count方法检查键是否存在(返回 0 表示不存在, 1 表示存在)

```c++
if (m.count("banana") > 0) {
    std::cout << "banana is in the map" << std::endl;
} else {
    std::cout << "banana is not in the map" << std::endl;
}
```

### 遍历 unordered_map

```c++
for (const auto& [k, v] : fruit_count) {
    std::cout << "Key: " << k << ", Value: " << v << std::endl;
}
```