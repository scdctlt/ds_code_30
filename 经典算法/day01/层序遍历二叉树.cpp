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