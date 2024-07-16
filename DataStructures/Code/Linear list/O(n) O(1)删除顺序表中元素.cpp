#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int Elemtype;

// 建立顺序表
typedef struct
{
    int data;
} Polynomial;

typedef struct
{
    Polynomial *elem;
    int length;
} Sqlist;

// 顺序表的初始化
void initialize(Sqlist &L)
{
    // 动态开辟结构体数组
    L.elem = (Polynomial *)malloc(MAXSIZE * sizeof(Polynomial));
    if (!L.elem)
    {
        return;
    }
    L.length = 0;
    // 顺序表的输入
    for (int i = 0; i < MAXSIZE; i++)
    {
        scanf("%d", &L.elem[i].data);
        L.length++;
    }
}

// 顺序表的删除
void deleteValue(Sqlist &L, Elemtype item)
{
    int index = 0;
    for (int i = 0; i < L.length; i++)
    {
        // 若当前元素值不是item,则把它移动到index位置去,最后未被移动的将会被删除
        if (L.elem[i].data != item)
        {
            L.elem[index].data = L.elem[i].data;
            index++;
        }
    }
    // 修改表的长度为index
    L.length = index;
}

int main()
{
}
