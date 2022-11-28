#include<bits/stdc++.h>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void delete_same(LinkList &L){
    LNode *r,*p=L->next;
    while (p)
    {
        r=p;
        p=p->next;
        if (p||p->data==r->data)
        {
            r->next=p->next;
            p=p->next;
        }
    }
}