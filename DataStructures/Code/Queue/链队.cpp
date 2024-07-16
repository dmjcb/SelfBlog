#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;

typedef struct
{
    char item;
    int data;
} Type;
typedef struct Node
{
    Type t;
    struct Node *next;
} Node, *NodeList;
typedef struct
{
    NodeList head;
    NodeList tail;
} Quene, *QueneList;

void initQuene(Quene &q)
{
    q.head = (NodeList)malloc(sizeof(Node));
    q.tail = q.head;
    q.head->next = NULL;
    cout << "" << endl;
}

void enterQuene(Quene &q, Type &t)
{
    NodeList p = (NodeList)malloc(sizeof(Node));
    if (p == NULL)
    {
        return;
    }
    p->t = t;
    p->next = NULL;
    q.tail->next = p;
    q.tail = q.tail->next;
}

void outQuene(Quene &q, Type &t)
{
    NodeList p = (NodeList)malloc(sizeof(Node));
    p = q.head->next;
    t = p->t;
    q.head->next = p->next;
    if (q.head->next == NULL)
    {
        q.tail = q.head;
    }
    free(p);
}

void PrintQueue(Quene *q)
{
    NodeList p;
    p = q->head->next;
    while (p)
    {
        cout << p->t.item << " " << p->t.data << endl;
        p = p->next;
    }
    cout << endl;
}

int getCarPositon2(Quene &q, Type &elem)
{
    int i = 1;
    for (NodeList p = q.head->next; p != NULL; p = p->next, i++)
    {
        if (elem.item == p->t.item && elem.data == p->t.data)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Quene q;
    Type t;
    initQuene(q);
    for (int i = 0; i < 3; i++)
    {
        cin >> t.item >> t.data;
        enterQuene(q, t);
    }

    cin >> t.item >> t.data;
    cout << getCarPositon2(q, t) << endl;
}
