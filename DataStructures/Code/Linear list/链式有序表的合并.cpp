#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Lnode {
    ElemType data;
    struct Lnode *next;
} Lnode,*Linklist;

//初始化
Lnode *initList(Linklist head) {
    head=(Linklist)malloc(sizeof(Lnode));
    head->next=NULL;
    return head;
}

//后插法建立链表
Lnode *inputList(Linklist &head,int n) {
    head->next=NULL;
    Linklist p,r;
    r=head;
    for(int i=0; i<n; i++) {
        p=(Linklist)malloc(sizeof(Lnode));
        scanf("%d",&p->data);
        p->next=NULL;
        r->next=p;
        r=p;
    }
    return head;
}

void mergeList(Linklist &head1,Linklist &head2,Linklist &head3) {
    Linklist p1,p2,p3;
    p1=head1->next;
    p2=head2->next;
    head3=head1;
    p3=head3;
    //两个表均为到末尾，则依次摘取
    while(p1&&p2) {
        //说明该摘取第一条链上的点
        if(p1->data<=p2->data) {
            //将这个节点与head3连接上
            p3->next=p1;
            //p3指向p1,为下一次连接做准备
            p3=p1;
            p1=p1->next;
        } else {
            //将这个节点与head3连接上
            p3->next=p2;
            //p3指向p1,为下一次连接做准备
            p3=p2;
            p2=p2->next;
        }
    }
    //将非空表的剩余部分与head3相连
    p3->next=p1?p1:p2;
    free(head2);
}

void ouputList(Linklist &head) {
    Linklist p=head->next;
    while(p) {
        printf("%d ",p->data);
        p=p->next;
    }
}

int main() {
    Linklist head1,head2,head3;
    head1=initList(head1);
    head2=initList(head2);
    head3=initList(head3);

    int n;
    scanf("%d",&n);
    head1=inputList(head1,n);
    scanf("%d",&n);
    head2=inputList(head2,n);

    mergeList(head1,head2,head3);
    ouputList(head3);

}
