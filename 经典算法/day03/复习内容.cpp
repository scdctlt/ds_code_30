// 1.复习 树的遍历递归和非递归
#include <bits/stdc++.h>
using namespace std;
typedef struct BiNode
{
    char data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

void visit(BiTree &t){
    cout<<t->data;
}

//递归遍历访问
void PreOrder(BiTree &t){
    if (t)
    {
        visit(t);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
}

//递归中序遍历
void InOrder(BiTree &t){
    if (t)
    {
        InOrder(t->lchild);
        visit(t);
        InOrder(t->rchild);
    }   
}

//递归后序遍历
void PostOrder(BiTree &t){
    if (t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        visit(t);
    }
}


//前序遍历非递归 
void PreOrder(BiTree &t){
    BiNode *p=t;   //遍历指针
    stack<BiNode *> s;   //访问过的结点存入栈中
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

//中序遍历非递归
void InOrder(BiTree &t){
    BiNode * p=t;
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
            s.pop();
            visit(p);
            p=p->rchild;
        }
    }
}


//后序遍历非递归
void PostOreder(BiNode *t){
    BiNode *p=t,*r;
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
            }
            else
            {
                s.pop();
                visit(p);
                r=p;
                p=NULL;
            }
        }
    }    
}

//层序遍历
void LevelOrder(BiTree &t){
    BiNode *p=t;
    queue<BiNode *> q;
    q.push(p);
    while (p||!q.empty())
    {
        p=q.front();
        visit(p);
        if (p->lchild)
        {
            q.push(p->lchild);
        }
        if (p->rchild)
        {
            q.push(p->rchild);
        }
    }
}




