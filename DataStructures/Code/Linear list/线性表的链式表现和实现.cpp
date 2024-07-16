#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
} Lnode, *Linklist;

// 初始化
Lnode *initList(Linklist head)
{
    head = (Linklist)malloc(sizeof(Lnode));
    head->next = NULL;
    return head;
}

// 后插法建立链表
Lnode *inputList(Linklist &head, int n)
{
    head->next = NULL;
    Linklist p, r;
    r = head;
    for (int i = 0; i < n; i++)
    {
        p = (Lnode *)malloc(sizeof(Lnode));
        scanf("%d", &p->data);
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return head;
}

// 查找
void getList(Linklist head, int index)
{
    Linklist p;
    p = head->next;
    // j为计数器，用以记录当前的位置
    int j = 1;
    // 当P不为空且未到指定位置时,指针向后移动,计数器增加
    while (p && j < index)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > index)
    {
        return;
    }
    printf("%d\n", p->data);
}

// 插入
void insertList(Linklist &head, int index, int e)
{
    Linklist p;
    p = head;
    // 计数器初始值为0是考虑到了空表的情况
    int j = 0;
    while (p && j < index - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > index - 1)
    {
        return;
    }
    Linklist s;
    s = (Linklist)malloc(sizeof(Lnode));
    ;
    s->data = e;
    s->next = p->next;
    p->next = s;
}

// 删除
void insertList(Linklist &head, int index)
{
    Linklist p;
    p = head;
    int j = 0;
    while ((p->next) && j < index - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > index - 1)
    {
        return;
    }
    Linklist q;
    q = p->next;
    p->next = q->next;
    free(q);
}

//
void ouputList(Linklist &head)
{
    Linklist p;
    p = head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    Linklist head;
    head = initList(head);
    int n;
    scanf("%d", &n);
    head = inputList(head, n);

    ouputList(head);
    return 0;
}
