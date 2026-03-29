#include <bits/stdc++.h>
using namespace std;
// 差分与前缀和为一对逆运算

// 差分数组元素的核心意义：它是其所在位置 (i, j) 的一个 “影响力种子”。当修改 D[i][j]时，这个变化会通过前缀和计算，扩散到所有以 (i, j) 为左上角的右下方向区域

// 对于num[]的二维差分矩阵diff[],其中中每个元素diff[i]等于num[i][j]-num[i-1][j]-num[i][j-1]+num[i-1][j-1]

const int N=1e3+10;
int n,m,q;
int num[N][N],diff[N][N];

void insert(int x1,int y1,int x2,int y2,int c)
{
    diff[x1][y1]+=c;
    diff[x1][y2+1]-=c;
    diff[x2+1][y1]-=c;
    diff[x2+1][y2+1]+=c;
}

int main()
{
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
            diff[i][j]=num[i][j]-num[i-1][j]-num[i][j-1]+num[i-1][j-1];
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            num[i][j]=num[i-1][j]+num[i][j-1]-num[i-1][j-1]+diff[i][j]; // 将diff[]看作原数组,num[]看作前缀和数组
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



