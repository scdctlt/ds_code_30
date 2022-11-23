//邻接矩阵转换成邻接表
#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;

void Convert_M_L(MGraph &M,ALGaph &L){
    L.arcnum=M.arcnum,L.vexnum=M.vexnum;        //邻接矩阵赋值给邻接表
    for (int i = 0; i < M.vexnum ; i++)     //初始化邻接表
    {
        L.vertices[i].firstarc = NULL;
    }
    for (int i = 0; i <M.vexnum ; i++)
    {
        for (int j = 0; i < M.vexnum; j++)
        {
            if (M.Edge[i][j])       //弧存在
            {
                //头插法
                ArcNode *p=new ArcNode;
                p->adjvex =j ;
                p->next = L.vertices[i].firstarc;
                L.vertices[i].firstarc = p;
            }
        }
    }
}
