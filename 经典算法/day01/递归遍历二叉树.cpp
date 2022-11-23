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
