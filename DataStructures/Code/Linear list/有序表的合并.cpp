#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *elem;
    int length;
} Sqlist;

void Init(Sqlist &s, const int n)
{

    s.elem = (int *)malloc(100 * sizeof(Sqlist));
    if (!s.elem)
    {
        return;
    }
    s.length = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s.elem[i]);
        s.length++;
    }
}

void Merge(Sqlist &s1, Sqlist &s2, Sqlist &s3)
{

    int e;
    int start1 = 0, start2 = 0, start3 = 0;
    int end1 = s1.length - 1;
    int end2 = s2.length - 1;

    s3.elem = (int *)malloc(200 * sizeof(Sqlist));
    s3.length = s1.length + s2.length;

    while (start1 <= end1 && start2 <= end2)
    {
        if (s1.elem[start1] <= s2.elem[start2])
        {
            s3.elem[start3++] = s1.elem[start1++];
        }
        else
        {
            s3.elem[start3++] = s2.elem[start2++];
        }
    }

    while (start1 <= end1)
    {
        s3.elem[start3++] = s1.elem[start1++];
    }
    while (start2 <= end2)
    {
        s3.elem[start3++] = s2.elem[start2++];
    }
}

void Output(Sqlist &L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main()
{
    Sqlist s1, s2, s3;
    int size1, size2;
    scanf("%d", &size1);
    Init(s1, size1);
    scanf("%d", &size2);
    Init(s2, size2);
    Merge(s1, s2, s3);

    Output(s3);
}
