#include <bits/stdc++.h>
using namespace std;
typedef struct  BiNode
{
    int data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

void visit(BiTree &t){
    if (t)
    {
        cout<<t->lchild;
    }
    
}


//递归遍历

void PreOrder(BiTree &t){
    if (t)
    {
        visit(t);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}


void InOrder(BiTree &t){
    if (t)
    {
        InOrder(t->lchild);
        visit(t);
        InOrder(t->rchild);
    }
    
}

void PostOrder(BiTree &t){
    if (t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        visit(t);
    }
    
}


//非递归遍历

void PreOrder(BiTree &t){
    BiNode *p=t;    //遍历指针
    stack<BiNode *> s;      //工作栈
    while (p || !s.empty())
    {
        if (p)
        {
            visit(p);
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}

void InOrder(BiTree &t){
    BiNode *p=t;
    stack<BiNode *> s;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.top();
            visit(p);
            s.pop();
            p=p->rchild;
        }        
    }
}


void PostOrder(BiTree &t){
    BiNode *p=t,*r=NULL;
    stack<BiNode *> s;
    while (p||!s.empty())
    {
        if (p)
        {
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.top();
            if (p->rchild!=NULL && p->rchild!=r)
            {
                p=p->rchild;
            }else
            {
                visit(p);
                s.pop();
                r=p;
                p=NULL;
            }
        }
    }
}

#define Maxsize 100

struct Sqlist
{
    int data[Maxsize];
    int length;
};



//插入某个元素的位置(1<i<n+1)
bool Insert(Sqlist &L,int i,int e){
    if (i<1 || i >L.length+1)
    {
        return false;
    }
    for (int j = L.length ; j>i; j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    
}


//删除某个位置的元素（1<i<n）

bool delete_elem(Sqlist &L,int i ,int &e){
    if (i<1 || i>L.length)
    {
        return false;
    }
    e=L.data[i-1];
    for (int j=i; j < L.length; j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;    
}

//合并两个升序顺序表
bool merge(Sqlist L1,Sqlist L2,Sqlist L3){
    if (L1.length+L2.length>L3.length)
    {
        return false;
    }
    int i,j,k=0;
    while (i<L1.length || j<L2.length)
    {
        if (L1.data[i]<=L2.data[j])
        {
            L3.data[k++]=L1.data[i++];
        }
    }
    while (i<L1.length)
    {
        L3.data[k++]=L1.data[i++];
    }
    while (j<L2.length)
    {
        L3.data[k++]=L1.data[j++];
    }
}

//删除升序顺序表重复元素
void delete_same(Sqlist L){
    int i,j;        //i存储第一个不同的元素，j为工作指针
    for (int j = 0; j < L.length; i++)
    {
        if (L.data[i]!=L.data[j])
        {
            L.data[++i]=L.data[j];
        }        
    }
}

typedef struct LNode
{
    /* data */
    int data;
    struct LNode *next;
}LNode,*LinkList;


//合并两个升序链表
bool merge(LinkList &L1,LinkList &L2,LinkList &L3){
    if (L1->next=NULL)
    {
        L3=L1;
        return true;
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