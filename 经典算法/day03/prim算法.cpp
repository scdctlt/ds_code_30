
#include <bits/stdc++.h>
using namespace std;

#define N 50
#define INF 0

int n,matrix[N][N];     //邻接矩阵，用于存储每个结点之间权值
int dis[N],Mincost;     //prim算法的dis数组 答案即为mincost
bool vis[N];    //prim算法的标记数组
void prim(){
    vis[1] = 1;     //默认从1号结点开始
    for (int i = 1; i < n; i++)
        dis[i]=matrix[1][i];        //dis存入1号村庄到结点成本
    for (int i = 0; i < n; i++)     //进行n-1次循环 每次将一个点加入（1号点已经加入，所有是n-1次）
    {
        int Min=INF,Minid;
        for (int j = 0; j<=n; j++)      //遍历选出当前成本最低的且未加入的点
        {
            if (vis[j]) continue;       //如果已经加入则跳过
            if (Min>dis[j])     //将j列为候选点
            {
                Minid = j;
                Min = dis[j];
            }
        }
        Mincost +=dis[Minid];       //更新答案
        vis[Minid] = 1;
        for (int j = 1; j <=n; j++)         //利用新加入的点更新dis数组
        {
            if (vis[j]) continue; 
            if (dis[j]>matrix[Minid][j])
            {
                dis[j]=matrix[Minid][j];
            }
        }
    }
}

int main(){
    scanf("%d",&n);     //读入结点数量
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            scanf("%d",&matrix[i][j]);      //读入权值
        }
    }
    prim();         //进入prim算法主过程
    printf("%d\n",Mincost);     //输出答案
    
}