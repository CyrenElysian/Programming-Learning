#include <bits/stdc++.h>
using namespace std;

// Dijkstra 算法的核心是贪心策略：每次从尚未确定最短距离的节点中，选出当前距离最小的节点，并认为这个节点的最短距离已经最终确定
// 这个结论成立的前提是所有边的权值非负。因为如果边权非负，那么通过其他节点（当前距离更大）绕路到达该节点，只会使路径更长，不可能更短
// 考虑三个节点 1、2、3，边如下：1 → 2，权值 5; 1 → 3，权值 2; 2 → 3，权值 -4

// SPFA（Shortest Path Faster Algorithm）不采用“一次确定”的贪心思想，而是通过反复松弛所有可能更新的边，直到没有更新为止
// 其核心机制是：用队列维护“距离发生变化的节点”。每次从队列中取出一个节点 u，尝试用它来更新所有邻接点 v
// 如果 dist[v] > dist[u] + w，则更新 dist[v]，并且如果 v 不在队列中，就将 v 入队
// 这个过程会不断重复，直到队列为空（即没有节点能被继续松弛）
// 由于 SPFA 允许同一个节点多次入队、多次被松弛，因此即使某条负权边在后期才被“发现”，也能及时修正之前可能错误的距离值
// 只要图中不存在负环，经过有限次松弛后，所有节点的距离都会收敛到真实最短路径

const int N=1e5+10;
int h[N],e[N],ne[N],w[N],idx;
bool state[N]; // 结点是否在队列中
int dist[N];
int q[N],head,tail=-1;

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

void spfa()
{
    q[++tail]=1; // 起点入队
    dist[1]=0;
    state[1]=true;
    while(tail>=head) // 循环直至队列为空
    {
        int a=q[head++]; // 取出队头结点
        state[a]= false;
        for(int i=h[a];i!=-1;i=ne[i]) // 遍历所有与a相邻的结点
        {
            int b=e[i];
            int c=w[i];
            if(dist[b]>dist[a]+c)
            // 找出最短距离变化的结点，更新距离并入队
            // 入队是因为该点的最短路径变化，可能会导致其到邻点的最短路径变化
            {
                dist[b]=dist[a]+c;
                if(!state[b])
                {
                    q[++tail]=b;
                    state[b]= true;
                }
            }
        }
    }
}

int main()
{
    memset(h,-1,sizeof h);
    memset(dist,0x3f, sizeof dist);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
    if(dist[n]==0x3f3f3f3f) cout<<"impossible";
    else cout<<dist[n];

    return 0;
}