#include<bits/stdc++.h>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

void head_build(LinkList &L,int array[],int n){
    L->next=NULL;
    for (int i = n-1; i >0; i++)
    {
        LNode *s= new LNode;
        s->data=array[i];
        s->next=L->next;
        L->next=s;
    }    
}

void tail_build(LinkList &L,int array[],int n){
    L->next=NULL;
    LNode *r=L->next;
    for (int i = 0; i < n; i++)
    {
        LNode *s= new LNode;
        s->data=array[i];
        r->next=s;
        r=s;
    }
    r=NULL;    
}