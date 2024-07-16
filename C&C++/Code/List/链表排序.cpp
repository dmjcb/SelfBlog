
#include <stdio.h>
#include <stdlib.h>
#define SNUM 4
struct student
{
    long num;
    int score;
    struct student *next;
};

struct student *sort(struct student *head)
{
    int i, j, score[SNUM], ts;
    long num[SNUM], y;
    struct student *p1;
    p1 = head;

    for (i = 0; i < SNUM; i++)
    {
        scanf("%ld %d", &num[i], &score[i]);
    }

    for (i = 0; i < SNUM - 1; i++)
    {
        for (j = 1; j < SNUM - i; j++)
        {
            if (num[j - 1] > num[j])
            {
                t = num[j - 1];
                num[j - 1] = num[j];
                num[j] = t;
                ts = score[j - 1];
                score[j - 1] = score[j];
                score[j] = ts;
            }
        }
    }

    for (i = 0; i < SNUM; i++)
    {
        p1->num = num[i];
        p1->score = score[i];
        p1->next = (struct student *)malloc(sizeof(struct student));
        p1 = p1->next;
    }
    p1->next = NULL;
    return head;
}

int main()
{
    struct student *head = (struct student *)malloc(sizeof(struct student)), *p1;
    p1 = sort(head);
    printf("\n");
    while (p1->next != NULL)
    {
        printf("%ld%d\n", p1->num, p1->score);
        p1 = p1->next;
    }
    return 0;
}
