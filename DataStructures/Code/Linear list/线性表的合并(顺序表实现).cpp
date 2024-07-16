/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2024-07-06 20:33:15
 * @LastEditors: dmjcb
 * @LastEditTime: 2024-07-07 14:18:19
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *elem;
    int length;
} Sqlist;

void initialize(Sqlist &L, const int n)
{
    L.elem = (int *)malloc(100 * sizeof(Sqlist));
    if (!L.elem)
    {
        return;
    }
    L.length = 0;
    printf("ʼɹ\n", L.length);
    // ˳
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &L.elem[i]);
        L.length++;
    }
}

int getElem(Sqlist &L, const int index)
{
    if (index >= L.length || index < 0)
    {
        printf("!");
        return 0;
    }
    return L.elem[index];
}

bool locateElem(Sqlist &L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            return true;
        }
    }
    return false;
}

void insertElem(Sqlist &L, int e)
{
    ++L.length;
    L.elem[L.length - 1] = e;
}

void mergeList(Sqlist &S1, Sqlist &S2)
{
    int size1 = S1.length;
    int size2 = S2.length;
    int e;
    for (int i = 0; i < size2; i++)
    {
        e = getElem(S2, i);
        if (locateElem(S1, e) == false)
        {
            insertElem(S1, e);
        }
    }
}

// ˳
void ouputElem(Sqlist &L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main()
{
    Sqlist S1, S2;
    int size1, size2;
    scanf("%d", &size1);
    initialize(S1, size1);
    scanf("%d", &size2);
    initialize(S2, size2);
    mergeList(S1, S2);
    ouputElem(S1);
}
