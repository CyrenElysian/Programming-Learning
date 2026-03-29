# include <bits/stdc++.h>
using namespace std;

// 对于n*n的棋盘，位于同一正斜线(/)的格子，其横坐标(i)与纵坐标(j)之和为一定值，且各斜线的值不同，故可用i+j标记一条正斜线
// 位于统一反斜线(\)的格子，其横坐标(i)和纵坐标(j)与n有如下关系：n-i+j = c ，c为一常数，且各斜线的值也不同，故可以用来标记反斜线

const int N=10;
char chess[N][N]; // 存储棋盘状态
// 记录正反斜线和列上是否有棋子
bool positive[2*N]; // n*n棋盘共2n-1条正（反）斜线
bool negative[2*N];
bool colum[N];

int n;
void dfs(int r)
{
    if(r > n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<chess[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++) // 判断第r行第i列是否放棋子
    {
        if(colum[i]==0 && positive[r+i]==0 && negative[n-r+i]==0)
        {
            chess[r][i]='Q';
            colum[i] = positive[r+i] = negative[n-r+i] =1;
            dfs(r+1); // 处理下一行
            chess[r][i]='.';
            colum[i] = positive[r+i] = negative[n-r+i] =0; // 恢复棋盘，进行下一轮循环
        }
    }
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  // 初始全部涂成点
    {
        for(int j=1;j<=n;j++)
        {
            chess[i][j]='.';
        }
    }
    dfs(1);
    return 0;
}
