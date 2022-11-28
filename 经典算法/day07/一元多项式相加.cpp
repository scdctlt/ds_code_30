#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int coef;       //系数
    int expn;       //指数
    struct Node *next    
}LNode,*poly;

void init(poly &La,poly &Lb){
    La = new LNode;
    Lb = new LNode;
    La->next= NULL;
    Lb->next=NULL;
    int m,n,coef,expn;
    scanf("%d",&m);
    scanf("%d",&n);
    for (int i = 0; i < m; i++)     //按照指数从小到大的顺序建立多项式A
    {
        scanf("%d",&expn);
        scanf("%d",&coef);
        poly p =new LNode;
        p->next=NULL;
        p->coef=coef;
        p->expn=expn;
        poly L=La;      //L指向头结点
        while (L->next!=NULL && p->expn>L->next->expn)      //找到La中第一个指数小于新输入结点指数值的那个结点前一个结点
        {
            L=L->next;
        }
        if (L->next!=NULL && p->expn==L->next->expn)            //指数相同，系数相加
        {
            L->next->coef+=p->coef;
        }
        else
        {
            p->next=L->next;        //插入p到恰当位置
            L->next=p;
        }      
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&expn);
        scanf("%d",&coef);
        poly p = new LNode;
        p->next=NULL;
        p->coef = coef;
        p->expn = expn;
        poly L =Lb;
        while (L->next!=NULL && p->expn>L->next->expn)      //找到Lb中第一个指数小于新输入结点指数值的那个结点前一个结点
        {
            L=L->next;
        }
        if (L->next!=NULL && p->expn==L->next->expn)            //指数相同，系数相加
        {
            L->next->coef+=p->coef;
        }
        else
        {
            p->next=L->next;        //插入p到恰当位置
            L->next=p;
        }
    }
}

void polyAdd(poly La,poly Lb){
    poly pa= La->next;
    poly pb = Lb->next;
    while (pa!=NULL && pb!=NULL)        
    {
        if (pa->coef == pb->expn)       //指数相同
        {
            if (pa->coef+pb->coef!=0)
            {
                printf("%d %d\n",pa->expn,pa->coef+pb->coef);
            }
            pa=pa->next;
            pb=pb->next;
        }
        else if (pa->expn < pb->expn)           //a的指数小于b的指数
        {
            printf("%d %d\n",pa->next,pa->coef);
        }else
        {
            printf("%d %d\n",pb->expn,pa->coef);
            pb=pb->next;
        }
        while (pa!=NULL)
        {
            printf("%d %d\n",pa->expn,pa->coef);
            pa=pa->next;
        }
        while (pb!=NULL)
        {
            printf("%d %d\n",pb->expn,pb->coef);
            pb=pb->next;
        }
    }
}

int main(){
    poly La;
    poly Lb;
    init(La,Lb);
    polyAdd(La,Lb);
}

