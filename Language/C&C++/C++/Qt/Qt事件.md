<!--
 * @Brief        : 
 * @Author       : dmjcb
 * @Date         : 2024-09-24 20:03:51
 * @LastEditors  : dmjcb@outlook.com
 * @LastEditTime : 2024-10-08 19:47:56
-->

# Qt 事件

> [Qt 博客汇总](https://www.cnblogs.com/linuxAndMcu/)

## 键盘事件

```c
#include <QKeyEvent>
```

### 按下

### 释放

## 鼠标事件

```c
#include <QMouseEvent>
```

### 按下

```c
void mousePressEvent(QMouseEvent *event);
```

- 判断鼠标键

```c
void MainWindow::mousePressEvent(QMouseEvent *event) {   
    // 左键被按下
    if (event->button() == Qt::LeftButton) {
        // ...
    }
    // 右键被按下
    if (event->button() == Qt::RightButton) {
        // ...
    }
}

```

### 释放

```c
void mouseReleaseEvent(QMouseEvent *event);
```

### 移动

```c
void mouseMoveEvent(QMouseEvent *event);
```
