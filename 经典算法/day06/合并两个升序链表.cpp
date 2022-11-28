#include <bits/stdc++.h>
using namespace std;
#define Maxsize 50

#include<bits/stdc++.h>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

bool merge(LinkList &L1,LinkList &L2,LinkList &L3){
    if (L1->next=NULL)
    {
        L3=L1;
        return true
    }
    if (L2->next=NULL)
    {
        L3=L2;
        return true;
    }
    LNode *p=L1->next,*q=L2->next,*r=L3;
    while (p||q)
    {
        if (p->data<=q->data)
        {
            r->next=p;
            r=p;
            p=p->next;
        }
        else
        {
            r->next=q;
            r=q;
            q=q->next;
        }
    }
    if (p)
    {
        r->next=p;
    }
    if (q)
    {
        r->next=q;
    }
    return true;    
}