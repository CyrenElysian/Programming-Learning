#include <bits/stdc++.h>
using namespace std;

const int N=310;
const int INF=1e9;
int weight[N],s[N]; // 记录每一堆的质量和前...堆的质量之和
int dp[N][N]; // dp[i][j]表示表示将第i堆到第j堆石子合并成一堆的最小代价

// 无论采用何种合并顺序，最终一定会有一个最后一次合并，将两堆石子合并成一堆
// 对于区间[i,j]，最后一次合并的两堆必然是由原序列中某个连续区间[i,k]合并成的一堆，
// 以及剩余部分[k+1,j]合并的一堆
// 假设在k处将区间分层两部分[i,k]和[k+1,j]，那么总代价为:
// dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum(i,j)), i<=k<=j，枚举求最小值
// sum(i,j)表示第i堆到第j堆的质量综合，即最后一次合并的代价
// 这个总和可以通过前缀和数组s[]快速得到

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>weight[i];
        s[i]=s[i-1]+weight[i];
    }

    // 枚举所有可能的区间，并计算每个区间合并的最小代价
    for(int len=2;len<=n;len++) // 枚举区间长度：len为区间长度
    {
        for(int i=1;i+len-1<=n;i++) // 枚举在区间长度下可能的左端点
        {
            int j=i+len-1; // 根据左端点，区间长度计算右端点
            dp[i][j]=INF;  // 初始区间最小代价为无穷大
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+(s[j]-s[i-1]));
            }
        }

    }

    cout<<dp[1][n]<<endl;

    return 0;
}
