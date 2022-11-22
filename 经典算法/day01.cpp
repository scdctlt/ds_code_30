// 树的遍历递归和非递归，和层序遍历
#include <bits/stdc++.h>
using namespace std;
typedef struct BiNode       //二叉树结点
{
    char data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

void visit(BiTree &T){      //visit操作
    cout<<T->data<<" ";
}


void PreOrder(BiTree &T){       //递归前序遍历二叉树
    if (T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }

}

void InOrder(BiTree &T){        //递归中序遍历二叉树
    if (T!=NULL)
    {
        
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }

}

void PostOrder(BiTree &T){      //递归后序遍历二叉树
    if (T!=NULL)
    {
        
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }

}

/** 非递归部分
 * 这里主要是考虑遍历的过程，栈和队列使用的是stl
*/

void PreOrder2(BiTree &T){
    stack<BiTree > s;
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
    stack<BiTree > s;
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
    stack<BiTree > s;
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

void levelOrder(BiTree &T){
    queue<BiNode *> q;
    BiNode *p=T;      //遍历指针  
    q.push(p);
    while (p || !q.empty())
    {
        p=q.front();
        visit(p);
        q.pop();
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