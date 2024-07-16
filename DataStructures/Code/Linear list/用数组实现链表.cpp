#include <stdio.h>

typedef struct list
{
    int data;
    struct list *next;
} Lnode, *Linklist;

int main()
{
    Lnode a[3] = {5, &a[1], 7, &a[2], 9, NULL};
    Linklist p = a;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}
