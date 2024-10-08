<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2024-09-10 02:06:36
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-27 21:21:49
-->

# boost编译过程

> [使用Docker搭建C++ Boost开发环境](https://bryantchang.github.io/2019/02/25/docker-boost/)

## 下载

[https://mirrors.aliyun.com/blfs/conglomeration/boost/](https://mirrors.aliyun.com/blfs/conglomeration/boost/)

下载指定版本源码, 此处以boost_1_80_0.tar.bz2为例

## Linux

### 解压

```sh
sudo tar -jxvf boost_1_80_0.tar.bz2
```

### 编译

```sh
cd boost_1_80_0
```

使用自带脚本, 生成b2引擎

```sh
sudo ./bootstrap.sh
```

使用b2引擎编译

```sh
sudo ./b2 --buildtype=complete install
```

## Windows

### VS2022编译

进入运行

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20240911_223643.jpg)

```
b2.exe install --build-type=complete --toolset=msvc-14.3 threading=multi --build-type=complete address-model=64
```

## 测试

```c++
// test.cpp
#include <iostream>
#include <boost/version.hpp>

int main() {
    std::cout << "Boost 版本" << BOOST_VERSION << std::endl;
    return 0;
}
```