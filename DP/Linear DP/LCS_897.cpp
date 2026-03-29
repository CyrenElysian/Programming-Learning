#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int dp[N][N]; // dp[i][j] 表示字符串A的前i个字符和字符串B的前j个字符的最长公共子序列
char a[N],b[N];
int main()
{
    int n,m;
    cin>>n>>m;
    cin>>(a+1)>>(b+1);

    // 遍历字符串a,b
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            // 如果a[i]=b[j]，在原最长公共子序列的基础上再加1 
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            // 如果不相等，长度不增长，则继承dp[i][j]前一项的最大值
            // 即dp[i-1][j]和dp[i][j-1]的最大值
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}

