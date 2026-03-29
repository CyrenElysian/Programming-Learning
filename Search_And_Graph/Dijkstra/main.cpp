# include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
const int M=1e5+10;

int e[M],ne[M],h[N],w[M],idx;
int state[N];
int dist[N];
// 保存起点到各个结点的距离，这个距离会随着不断探寻发生变化，最终为各结点的最短路径
int n,m;

void add(int a,int b,int weight)
{
    e[idx]=b;
    w[idx]=weight;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

void Dijkstra()
{                                                  
    memset(dist,0x3f, sizeof(dist));
    dist[1]=0;
    for(int i=1;i<=n;i++) // 每次循环都会确定一个结点的最短路径
    {
        int t=-1;
        for(int j=1;j<=n;j++) // 寻找当前距离源点且未确定最短路径的结点
        {
            if(!state[j] && (t==-1 || dist[j]<dist[t]))
            // j结点未达到最短路径，且本次探寻结点的路径更小或者为首次探寻
            {
                t=j;  
            }
        }
        state[t]=true;
        // 标记结点t的最短路径已确定，从t出发开始探寻，更新dist[]
        for(int j=h[t];j!=-1;j=ne[j])
        {
            int k=e[j]; // 终点为k
            dist[k]=min(dist[t]+w[j],dist[k]);
        }
    }
}

int main()
{
    memset(h,-1, sizeof(h));
    cin>>n>>m;
    while(m--)
    {
        int a,b,weight;
        cin>>a>>b>>weight;
        add(a,b,weight);
    }
    Dijkstra();
    cout<<(dist[n]==0x3f3f3f3f ? -1:dist[n])<<endl;

    return 0;
}