/*
邻接矩阵的定义
*/

#define MaxVertexNum 100        //顶点数目的最大值
typedef char VertexType;        //顶点的数据类型
typedef int EdgeType;       //带权图中边权值的数据类型
typedef struct MGraph
{
    VertexType Vex[MaxVertexNum];        //顶点表
    EdgeType  Edge[MaxVertexNum][MaxVertexNum];      //邻接矩阵，边表
    int vexnum,arcnum;          //图的当前顶点数和弧数
}MGraph;


/*
邻接表的定义
*/

typedef struct ArcNode          //边表结点
{
    int adjvex;                 //该弧指向的顶点位置
    struct ArcNode *next;       //指向下一条弧的指针
}ArcNode;

typedef struct VNode            //顶点表结点
{
    VertexType data;        //顶点信息
    ArcNode *firstarc;         //指向第一条依附该节点的弧的指针
}VNode,AdjList[MaxVertexNum];

typedef struct ALGaph
{
    AdjList vertices;           //邻接表
    int vexnum,arcnum;          //图的顶点数和弧数
}ALGaph;                        //ALGraph是以邻接表存储的图类型
