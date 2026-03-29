#include <iostream>
using namespace std;

// 用 g[i][j] 表示从前 i 种物品中进行选择，且总体积不大于 j 的各个选法获得的价值的集合
// 注意：g[i][j] 不是一个数，是一堆数
// 用 f[i][j] 表示从前 i 种物品中进行选择，总体积小于等于 j 所能获得的最大价值
// 很明显，f[i][j] 就是 g[i][j] 中的最大值

// 对于f[i][j]
// 第 i 种物品选 0 个对应所有选法获的价值的集合，最大值是 f[i - 1][j]
// 第 i 种物品选 1 个对应所有选法获的价值的集合，最大值是 f[i-1][j - v_i] + w_i
// 第 i 种物品选 k 个对应所有选法获的价值的集合，最大值是 f[i-1][j - x*v_i] + x*w_i
// 可以推出，f[i][j]=max(f[i-1][j - x*v_i] + x*w_i)
int n,volume;
const int N=1e4+10;
int v[N],w[N];
int f[N][N];

int main()
{
    cin>>n>>volume;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=volume;j++)
        {
            for(int k=0;k*v[i]<=j;k++)
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<f[n][volume]<<endl;
    
    return 0;
}

