<!--
 * @Brief        : 
 * @Author       : dmjcb@outlook.com
 * @Date         : 2023-09-16 16:02:42
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-09-27 21:03:03
-->

# CMake使用

```cpp
// Main.cpp
#include<iostream>

int main(void) {
    std::cout << "Hello World" << std::endl;\

    return 0;
}
```

## 创建 CMakeLists.txt

```sh

project(Hello)

set(SRC_LIST Main.cpp)

add_executable(Hello ${SRC_LIST})
```

## 配置

### 运行cmake指令

- 使用当前目录CMakeList.txt, 当目录构建

```sh
cmake build
```

- 使用当前目录CMakeList.txt, 指定build目录构建

```sh
cmake -B build
```

- 指定src目录的CMakeList.txt, 指定构建目录build

```sh
cmake -S src -B build
```

### CMake 执行分析

CMake 会读取并解析 CMakeLists.txt 文件、检查系统环境、依赖库、编译器设置等

将变量(如 CMAKE_CXX_STANDARD、CMAKE_BUILD_TYPE)等赋值

生成对应平台的构建文件, 例如在 Unix 系统上会生成 Makefile

### 检测依赖

如果项目依赖第三方库(如 Boost、Qt 等), CMake 会在这一步检查这些库是否安装, 以及它们的位置

如果需要, CMake 会自动找到这些库并链接到工程中

## 生成

这一阶段 CMake 生成的构建系统文件将被调用, 开始实际的编译和链接操作

### 构建

- 当前目录编译

```sh
cmake --build .
```

- 在build目录下编译

```sh
cmake --build build
```

### 编译源文件

构建系统会调用指定的编译器(如 g++ 或 clang++)来编译项目中的源代码文件(如 .cpp 文件)

CMake 会自动处理依赖关系, 如果某个源文件没有修改过, 那么它不会重新编译

### 链接生成目标文件

编译器会将编译好的目标文件链接成最终的可执行文件或库文件(动态库或静态库)

链接器会根据 CMake 的配置将依赖的库文件正确地链接到目标文件中

### 输出可执行文件或库

最终的可执行文件或库文件会出现在 CMake 配置的输出目录(通常是 build/ 目录）中

![](https://raw.githubusercontent.com/dmjcb/SelfImgur/main/20231202004223.png)

## 后处理

- 在build目录下安装

```sh
cmake --install build
```

## 卸载

[卸载 make install 编译安装的软件](https://blog.csdn.net/reasonyuanrobot/article/details/106732047)