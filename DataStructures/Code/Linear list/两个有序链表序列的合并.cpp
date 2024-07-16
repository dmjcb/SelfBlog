#include <iostream>
#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    list *next;
} Lnode, *Linklist;

Linklist inputList(Linklist &head)
{
    head = (Linklist)malloc(sizeof(Lnode));
    head->next = NULL;
    Linklist p, r;
    r = head;
    while (1)
    {
        p = (Linklist)malloc(sizeof(Lnode));
        scanf("%d", &p->data);
        if (p->data == -1)
        {
            break;
        }
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return head;
}

void ouputList(Linklist &head)
{
    Linklist p;
    p = head->next;
    while (p->next->next)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    p = p->next;
    printf("%d ", p->data);
}

void connectList(Linklist &head1, Linklist &head2)
{
    Linklist p1, p2;
    p1 = head1->next;
    while (p1->next)
    {
        p1 = p1->next;
    }
    p2 = head2->next;
    p1->next = p2;
    free(head2);
}

int main()
{
    Linklist head1, head2;
    head1 = inputList(head1);
    head2 = inputList(head2);
    connectList(head1, head2);
    ouputList(head1);
}
