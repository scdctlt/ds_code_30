// 1.复习 树的遍历递归和非递归
#include <bits/stdc++.h>
using namespace std;
typedef struct BiNode
{
    char data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;










//2. dfs与bfs 和邻接表邻接矩阵转化
using namespace std;
#define MaxVertexNum 100        //顶点数目的最大值
typedef char VertexType;        //顶点的数据类型
typedef int EdgeType;       //带权图中边权值的数据类型
typedef struct MGraph
{
    VertexType Vex[MaxVertexNum];        //顶点表
    EdgeType  Edge[MaxVertexNum][MaxVertexNum];      //邻接矩阵，边表
    int vexnum,arcnnum;          //图的当前顶点数和弧数
}MGraph;
