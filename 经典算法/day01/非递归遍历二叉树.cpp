#include <bits/stdc++.h>
using namespace std;
typedef struct BiNode       //二叉树结点
{
    char data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;
/** 非递归部分
 * 这里主要是考虑遍历的过程，栈和队列使用的是stl
*/
void visit(BiTree &T){      //visit操作
    cout<<T->data<<" ";
}


void PreOrder2(BiTree &T){
    stack<BiNode * > s;
    BiNode *p = T;           //p是遍历指针
    while (p||!s.empty())
    {
        if (p)
        {
            visit(p);
            s.push(p);
            p=p->lchild;        //左孩子不空，一直向左走
        }
        else
        {
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}


void InOrder2(BiTree &T){           //非递归中序遍历二叉树
    stack<BiNode *> s;
    BiNode *p = T;           //p是遍历指针
    while (p||!s.empty())
    {
        if (p)
        {
            s.push(p);     //当前结点入栈
            p=p->lchild;        //左孩子不空，一直向左走
        }
        else            //出栈转向出栈节点的右子树
        {
            p=s.top();          //栈顶元素赋值给p并出栈
            s.pop();
            visit(p);       //访问当前结点
            p=p->rchild;        //向右孩子走，p赋值为当前结点的右孩子
        }
    }
}

void PostOrder2(BiTree &T){
    stack<BiNode *> s;
    BiNode *p = T;           //p是遍历指针
    BiNode *r=NULL;
    while (p||!s.empty())
    {
        if (p)
        {
            s.push(p);
            p=p->lchild;        //左孩子不空，一直向左走
        }
        else
        {
            p=s.top();
            if (p->rchild&&p->lchild!=r)        //右子树存在且没有被访问过
            {
                p=p->rchild;
            }
            else
            {
                p=s.top();
                s.pop();
                visit(p);
                r=p;
                p=NULL;
            }
        }
    }
}