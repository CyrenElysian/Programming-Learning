#include <bits/stdc++.h>
using namespace std;

const int N=210;
const int INF= 1e7+10;

int n;
int dist[N][N];
// Floyd算法经过n次(结点数)循环，第k次循环计算每个点经过点k后，到达其他点的最短路径
void Floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main()
{
    int m,Q;
    cin>>n>>m>>Q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }

    while (m--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        dist[x][y]=min(dist[x][y],w); // 重复边保留最小值
    }

    Floyd();

    while(Q--)
    {
        int x,y;
        cin>>x>>y;
        if(dist[x][y]>INF/2) cout<<"impossible"<<endl;
        // 可能有负权边，使得距离略小于INF
        // eg :A到B权为-10，B到C不可达，为INF，无其他边
        // A到C为INF-10，略小于INF，实际不可达
        else cout<<dist[x][y]<<endl;
    }

    return 0;
}