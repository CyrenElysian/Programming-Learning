# include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int e[N],ne[N],h[N],idx;
int d[N]; // 保存各个点的入度，依次删去入度为0的点以及其关联边
          // 若所有点均能被删除，则这个图可以进行拓扑排序
int n,m; // 结点数和边数
int q[N]; // 队列保存入度为0的点
int head,tail=-1; // 队头和队尾指针

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

void topology_sort()
{
    for(int i=1;i<=n;i++) // 将入度为0的点入队
    {
        if(d[i]==0) q[++tail]=i;
    }
    while(tail>=head) // 尾大于等于头，说明队列里还有结点
    {
        int a =q[head++];
        for(int i=h[a];i!=-1;i=ne[i])
        {
            int b=e[i];
            d[b]--; // 边的中点减去一点入度
            if(d[b]==0) q[++tail]=b;
        }
    }
    if(tail==n-1) // 队列中的点个数与结点总数相同，可以进行拓扑排序，依次输出即为答案
    {
        for(int i=0;i<n;i++)
        {
            cout<<q[i]<<" ";
        }
    }
    else cout<<-1;
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof (h));
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        d[b]++;
        add(a,b);
    }
    topology_sort();
    return 0;
}