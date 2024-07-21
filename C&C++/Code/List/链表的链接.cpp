/*
 * @Description:
 * @Version: 1.0
 * @Author: dmjcb
 * @Email:
 * @Date: 2022-03-29 21:57:16
 * @LastEditors: dmjcb
 * @LastEditTime: 2022-03-29 22:14:00
 */
#include <stdio.h>
#include <stdlib.h>
struct student
{
    long num;  /*学号*/
    int score; /*成绩*/
    struct student *next;
};

// 程序首先完成创建两个链表,要求补充完成实现将第二个链表合并到第一个链表未尾的函数。
struct student *merge(struct student *head, struct student *head1)
{
    struct student *g_St;
    g_St = head;
    g_St->next = head1;
    head1->next = NULL;
    return g_St;
}

int main()
{
    struct student *head = (struct student *)malloc(sizeof(struct student));
    struct student *head2 = (struct student *)malloc(sizeof(struct student));
    scanf("%ld %d", &head->num, &head->score);
    scanf("%ld %d", &head2->num, &head2->score);
    merge(head, head2);
    printf("%ld %d\n", head->num, head->score);
    printf("%ld %d", head->next->num, head->next->score);
    return 0;
}
