#include<bits/stdc++.h>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

// 求链表长度
int LinkList_len(LinkList &L){
    LNode *p=L->next;
    int len=0;
    while (p)
    {
        len++;
        p=p->next;
    }
    return len;
}

LinkList find_addr(LinkList &L1,LinkList &L2){
    LNode *p,*q;
    int m,n;
    m=LinkList_len(L1);
    n=LinkList_len(L2);
    for (p=L1; m>n; m--)
    {
        p=p->next;
    }
    for (q=L2; n>m ; n--)
    {
        q=q->next;
    }
    while (p->next!=NULL&&p->next!=q->next)
    {
        p=p->next;
        q=q->next;
    }
    return p->next;
}