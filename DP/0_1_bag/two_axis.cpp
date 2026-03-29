#include <iostream>
using namespace std;

const int N = 1010;
int v[N];    // 体积
int w[N];    // 价值
int dp[N][N];  // dp[i][j], j体积下前i个物品的最大价值

int main()
{
    int n, m; // 定义物体数量n，背包容量m
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
            if(j < v[i])
                dp[i][j] = dp[i - 1][j];
                // 能装，需进行决策是否选择第i个物品
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }

    cout << dp[n][m] << endl;

    return 0;
}

