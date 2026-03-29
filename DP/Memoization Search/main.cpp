#include <bits/stdc++.h>
using namespace std;

const int N=310;
int f[N][N]; // 表示从点(x,y)出发能够得到的最长下降路径长度（包括自身）
int height[N][N]; // 存储(i,j)的高度
int dx[4]={0,0,-1,1}; // 方向
int dy[4]={1,-1,0,0};

int n,m;
int dp(int x,int y)
{
    int &v = f[x][y];
    if(v!=-1) return v; // 用 -1 标记未计算
    v=1; // 初始化为1(自身)
    for (int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=1 && xx<=n && yy>=1 && yy<=m &&height[x][y]>height[xx][yy])
        {
            v=max(v,dp(xx,yy)+1);
        }
    }
    return v;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>height[i][j];
        }
    }
    memset(f,-1,sizeof f);

    int res=0;
    for(int i=1;i<=n;i++)  // 遍历滑雪场每个可能的起点
    {
        for(int j=1;j<=m;j++)
        {
            res=max(res,dp(i,j));
        }
    }
    cout<<res<<endl;

    return 0;
}
