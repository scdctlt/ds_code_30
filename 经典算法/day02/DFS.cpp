#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;



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