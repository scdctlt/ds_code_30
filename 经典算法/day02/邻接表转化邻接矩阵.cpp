#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;

// 邻接表转化成邻接矩阵
void ConvertL_M(ALGaph &G,MGraph &M){
    for (int i = 0; i < G.vexnum ; i++)
    {
        ArcNode *p;                     //定义表结点
        p=(G.vertices[i]).firstarc;        //指向第一条弧的指针
        while (p!=NULL)
        {
            M.Edge[i][p->adjvex]=1;     
            p=p->next;                  //取出下一条弧
        }
    }  
}