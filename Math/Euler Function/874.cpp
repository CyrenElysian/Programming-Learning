// 对于任意合数x=i*p，其中p是x的 最小质因子 ，我们可以利用已知的E(i)计算E(x)
// 如果p与i互质，E(i*p)=E(i)*E(p)=E(i)*(p-1)
// 如果p与i不互质，E(i*p)=E(i)*E(p)=E(i)*p （推导见图）

// 算法流程
// 初始化E(1)=1,用数组st[]标记合数，用primes[]记录质数
// 1.遍历i [2,n]，如果i未被标记（st[i]为false），则i是质数，将其加入primes[]，并令E(i)=i-1
// 2.对于每个质数p（需保证p*i<=n），标记p*i为合数
// 3.如果i%p==0，则p是i的最小质因子（比p小的质数所得到的合数st[i]已被标记为true)
// 利用公式E(i*p)=E(i)*p
// 4.否则，p与i互质，利用公式E(i*p)=E(i)*(p-1)

#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int cnt; // 指针
int primes[N];
bool st[N];
int euler[N];

void Euler_Function(int n)
{
    euler[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            euler[i]=i-1;
        }
        for(int j=0;primes[j]<=n/i;j++)
        // 遍历当前已找到的质数数组primes[]，并乘积不超过范围上限
        {
            int t=primes[j]*i; // 依次用每个质数去和 i 相乘，标记合数
            st[t]=true;
            if(i%primes[j]==0)
            // 如果当前质数 primes[j] 是 i 的最小质因子，此时合数 t 的最小质因子也是 primes[j]
            {
                euler[t] = euler[i] * primes[j];
                break;
                // 避免用更大的质数prime[j+1]取处理t'=primes[j+1]*i，
                // 因为已知i%prime[j]==0，所以t'%prime[j]肯定为0
                // t'的最小质因子应该是prime[j]而不是prime[j+1]
                // 例如：当i=4时，若没有break，j依然会从0增到1
                // 计算t：t=prime[1]*4=3*4=12，然而12的最小质因子应该是2
            }
            else
            {
                euler[t] = euler[i] * (primes[j] - 1);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    Euler_Function(n);

    long long res=0;
    for(int i=1;i<=n;i++) res+=euler[i];

    cout<<res<<endl;
}