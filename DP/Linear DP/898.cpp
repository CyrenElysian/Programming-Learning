#include <bits/stdc++.h>
using namespace std;
const int N=510;
const int INF=1e9;
int a[N][N],f[N][N];
// a[][]记录数值，f[i][j]记录到(i,j)的最大和

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

    for(int i=1;i<=n;i++)
    // 需要考虑边界情况，左侧和右侧f值的推导会用到编号0和i+1，需要充分初始化
    {
        for (int j = 0; j <= i + 1; j++) {
            f[i][j] = -INF;
            // i,j从0开始初始化，因为下面涉及到到f[i'-1][j'-1](i',j'从1开始)
        }
    }
    f[1][1]=a[1][1];

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
        }
    }

    int ans=-INF;
    for(int k=1;k<=n;k++)
    {
        ans=max(ans,f[n][k]);
    }
    cout<<ans<<endl;
    
        
    return 0;
}
