#include <bits/stdc++.h>
using namespace std;

// 1. dist[] 数组的常规作用
// 在最短路径算法（如SPFA）中，dist[u] 通常表示从某个源点到节点 u 的当前最短距离
// 我们通过不断松弛来更新这些距离，最终得到源点到各点的最短路径
// 但在判断负环的问题中，我们并不关心具体的最短路径值，而是想知道是否存在一个环，使得沿着它走一圈后距离可以无限减小。
// dist[] 在这里的作用是作为松弛操作的触发器——只要有一条边能使得 dist[u] + w < dist[v]，我们就更新 dist[v]，并记录路径边数 cnt[v]
// 当某个点的 cnt 达到 n 时，就说明存在负环。
//
// 2. 为什么将所有点的 dist 初始化为 0？
//（1）保证负环能被检测到
// 假如我们只从一个源点出发（比如节点1），并将 dist[1]=0，其他点设为无穷大，那么只有从源点能到达的负环才会被检测到。
// 如果负环在另一个不连通的区域，它永远不会被松弛，也就无法发现
// 而将所有点的 dist 都设为 0，相当于我们同时从所有点出发。这样，无论负环在哪里，环上的点一开始就在队列中，并且距离为0
// 当沿着负环走一圈时，由于环的总权为负，经过一圈后回到同一个点，距离会变成负数（比如从0变成-1），这就会触发松弛，
// 从而不断更新，cnt 持续增加，最终达到 n 检测到负环
//（2）dist 的值本身并不重要
// 在检测负环的过程中，我们并不需要 dist 的真实最短距离，只需要它能不断变小（因为负环的存在会导致无限变小）
// 初始值设为0只是一个方便的选择，设为任何常数都可以，因为只要存在负环，沿着环走总会使 dist 变得更小，从而持续松弛

const int N=2e3+10;
const int M=1e4+10;

int n,m;
int h[N],w[M],e[M],ne[M],idx;
int dist[N]; 
int cnt[N]; // 用于记录到达当前点的最短路径边数
bool state[N]; // 标记是否在队列中

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool spfa()
{
    queue<int> q;
    // 用队列维护“距离发生变化的节点”，与之前用spfa计算最短路径（无负环）不同的是，
    // 这里是判断是否有负环，为了确保能从任意点出发开始搜索，将所有结点入队
    //（保证任何负环都能被发现，如果不连通可能存在孤立负环）
    // 同时初始化dist[]为0
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        state[i]= true;
    }

    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        state[t]= false;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if (dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;

                if(cnt[j]>=n) return true; // n个结点，最短路径至多经过n-1结点
                if(!state[j])
                {
                    q.push(j);
                    state[j]= true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    if(spfa()) cout<<"Yes";
    else cout<<"No";

    return 0;
}