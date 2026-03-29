#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
char a[N],b[N];
int dp[N][N];
// dp[i][i] 表示字符串A的前i个字符转换成字符串B的前j个字符所需要的最少操作次数
// 初始化 dp[0][j]=j: 将空字符串变成 B 的前 j 个字符，需要执行 j 次插入操作
//       dp[i][0]=i: 将 A 的前 i 个字符变成空字符串，需要执行 i 次删除操作
// 考虑 A[i]和B[j]
// 如果当前字符相同，则不需额外操作：dp[i][j]=dp[i-1][j-1]
// 如果不同，则从三种操作中选一下代价最小的：
// 1.将A的前i-1个字符变为B的前j个字符，再删去A[i]，即dp[i][j]=dp[i-1][j]+1
// 2.将A的前i个字符变为B的前j-1个字符，再插入B[j]，即dp[i][j]=dp[i][j-1]+1
// 3.将A的前i-1个字符变为B的前i-1个字符，再替换A[i]为B[j]，即dp[i][j]=dp[i-1][j-1]+1

int main()
{
    int n,m;
    cin>>n>>(a+1);
    cin>>m>>(b+1);

    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int j=0;j<=m;j++) dp[0][j]=j;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            // min()中比较对象多余两个，要加{}
        }
    }

    cout<<dp[n][m]<<endl;
    return 0;
}
