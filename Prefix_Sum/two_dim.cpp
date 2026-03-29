#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int num[N][N];
int prefix[N][N];

// 二维前缀和矩阵中的每个元素，其核心意义在于它存储了从原矩阵固定起点（通常是左上角 (0,0)）到当前位置 (i,j) 所围成的矩形区域内所有元素的累计和。

int main()
{
    int n,m,q; // n行m列矩阵,q次询问；
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>num[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+num[i][j]; // 二维前缀和计算公式
            // 二维前缀和指的是矩阵某点所在行和列(包括在内)，左上角元素的总和
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<prefix[x2][y2]-prefix[x2][y1-1]-prefix[x1-1][y2]+prefix[x1-1][y1-1]<<endl;
        // 求两个点所构成的矩阵的元素之和(两点位置为矩阵对角)
    }
    return 0;
}