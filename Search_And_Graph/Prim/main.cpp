#include <bits/stdc++.h>
using namespace std;

// Prim 算法是一种加点法，它从一个起始点出发，
// 逐步将距离当前生成树最近的点及其连接边加入树中，直到所有点都连通

const int N=510;
int graph[N][N]; // 存储两点之间的最小边权
int dist[N]; // 记录各结点到当前最小生成树的距离，即最小权值
bool state[N];

const int INF =0x3f3f3f3f;
int n; // 点数
int res=0 ; // 权值和
int prim()
{
    memset(dist,0x3f, sizeof(dist));
    dist[1]=0;
    

    for(int i=1;i<=n;i++) // 每轮将一个距离最小生成树最小的加入最小生成树
    {
        int t=-1; // 每轮初始化一个结点
        for(int j=1;j<=n;j++)  // 循环n次，寻找距离最小生成树最小的距离
        {
            if(!state[j] && (t==-1 || dist[j]<dist[t]))
                t=j;
        }

        if(dist[t]==INF) return INF;
        res+=dist[t];
        state[t]= true;

        for(int j=1;j<=n;j++)  // 更新最短距离
        {
            if(!state[j] && (graph[t][j]<dist[j]))
                dist[j]=graph[t][j];
        }
    }

    return res;
}

int main()
{
    int m;
    cin>>n>>m;
    memset(graph,0x3f,sizeof(graph));

    while(m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        if(x==y) continue; // 自身与自身的边权值默认为INF，最小生成树不允许出现自环
        graph[x][y]=graph[y][x]=min(w,graph[x][y]);
    }

    int ans=prim();
    if(ans==INF) cout<<"impossible";
    else cout<<ans;

    return 0;
}
