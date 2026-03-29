// 该方法自底向上递推，不需要考虑边界问题
// 在自顶向下的方法中，递推时会出现边界外的数，f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j]
// 故需要初始化f为-INF来确保max函数取到正确的结果，但在自底向上的方法中则不需要

#include <bits/stdc++.h>
using namespace std;

const int N=510;
int a[N][N],f[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }

    // 初始化最后一行
    for(int k=1;k<=n;k++)
        f[n][k]=a[n][k];

    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];

    cout<<f[1][1]<<endl;
    return 0;
}
