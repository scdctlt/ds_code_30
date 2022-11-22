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






/********************************************/
//
//
//2. dfs与bfs 和邻接表邻接矩阵转化
//
//
//
/********************************************/

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

typedef struct 
{
    AdjList vertices;           //邻接表
    int vexnum,arcnum;          //图的顶点数和弧数
}ALGaph;                        //ALGraph是以邻接表存储的图类型

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

//邻接矩阵转换成邻接表

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




//DFS
int matrix[7][7]={
    //0 1 2 3 4 5 6
    //A B C D E F G 
/*A*/{0,0,1,1,0,1,0},
/*B*/{0,0,1,0,0,0,0},
/*C*/{1,1,0,1,0,0,0},
/*D*/{1,0,1,0,0,0,0},
/*E*/{0,0,0,0,0,0,1},
/*F*/{1,0,0,0,0,0,1},
/*G*/{0,0,0,0,1,1,0},
};
bool vis[7];    //标记数组
//搜索最大层数
struct node
{
    int index;
    int dep;
    /* data */
};
int maxx=0;

void bfs(){
    queue<node> q;
    q.push(node{0,1});
    vis[0]=1;
    while (!q.empty())
    {
        node temp=q.front();
        cout<<char(temp.index+'A');
        maxx=max(maxx,temp.dep);
        q.pop();
        for (int i = 0; i < 7; i++)
        {
            if (matrix[temp.index][i]==1&&!vis[i])
            {
                q.push(node{i,temp.dep+1});
                vis[i]=1;
            }  
        }  
    }
}


//DFS

int matrix[7][7]={
    //0 1 2 3 4 5 6
    //A B C D E F G 
/*A*/{0,0,1,1,0,1,0},
/*B*/{0,0,1,0,0,0,0},
/*C*/{1,1,0,1,0,0,0},
/*D*/{1,0,1,0,0,0,0},
/*E*/{0,0,0,0,0,0,1},
/*F*/{1,0,0,0,0,0,1},
/*G*/{0,0,0,0,1,1,0},
};
bool vis[7];    //标记数组
//将结点入栈，接着将其出栈，（入过栈的需要标记），
// 出栈结点的邻接点均入栈，直到其结点均无未入栈的邻接点且栈空为止

/* 深度优先搜索：
1.先进后出
2.标记-防止重复搜索
3.邻接点（邻接矩阵）
*/
//求最长挖掘深度
//dfs(/*参数*/)-状态（index）,dep深度
//
int maxx=0;
int num=0;

void dfs(int index,int dep){
    vis[index] = 1;
    cout<<char(index+'A');
    maxx=max(maxx,dep);
    num=num+1;
    for (int i = 0; i < 7; i++)
    {
        if (matrix[index][i]==1 && !vis[i])
            dfs(i,dep+1);   
    }
}
//vis    ACB
//output ACB
//1. dfs(A)-> dfs(C)   {dfs(C)结束返回继续往下调用}-> dfs(F) {dfs(F)结束返回继续往下调用} return
//2. dfs(F) ->dfs(G)    {dfs(G)结束返回继续往下调用} return
//3. dfs(G)->dfs(E) {dfs(E)结束返回继续往下调用} return
//4. dfs(E) return
//2. dfs(C)-> dfs(B) {dfs(B)结束返回继续往下调用}-> dfs(D)  {dfs(D)结束返回继续往下调用}->return 
//3. dfs(D)  return 
//3. dfs(B)  return

int main(){
    dfs(0,1);       //从A开始搜索
    cout<<"\n最长搜索深度:"<<maxx;
    cout<<"搜索次数为:"<<num;
    return 0;
}