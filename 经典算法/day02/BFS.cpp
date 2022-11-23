#include<bits/stdc++.h>
#include"Graph.h"
using namespace std;


//BFS
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