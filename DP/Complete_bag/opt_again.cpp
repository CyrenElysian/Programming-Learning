#include<iostream>

// f[i][j] = max(f[i][j],f[i-1][j-v[i]]+w[i]); 01背包
// f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]); 完全背包问题
// 类似 0-1 背包，进一步优化代码，区别在于：
// 对于完全背包，每个物品可以无限次使用，所以我们需要利用当前物品多次选取的可能性
// 正序遍历允许 dp[j - V[i]] 已经被当前物品更新过，这样在后续更大的容量中，就可以再次叠加当前物品，实现无限次选取的效果
// 因此，完全背包的内层循环是顺序的

// for(int i = 1 ; i<=n ;i++)
//    for(int j = v[i] ; j<=volume ;j++)
//    // 注意，这里的j是从小到大枚举，和01背包不一样
//    {
//            f[j] = max(f[j],f[j-v[i]]+w[i]);
//    }
using namespace std;
const int N = 1010;
int f[N];
int v[N],w[N];
int main()
{
    int n,volume;
    cin>>n>>volume;
    for(int i = 1 ; i <= n ;i ++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i = 1 ; i<=n ;i++)
        for(int j = v[i] ; j<=volume ;j++)
        {
            f[j] = max(f[j],f[j-v[i]]+w[i]);
        }
    cout<<f[volume]<<endl;
}

