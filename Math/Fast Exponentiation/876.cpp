#include <bits/stdc++.h>
using namespace std;

// 乘法逆元的概念
// 在模运算中，对于整数a和模数m，如果存在整数x，使得a*x mod m≡1，称x是a模m的乘法逆元
// 例如，4*1 mod 3 =1，则1是4模3的乘法逆元
// 逆元存在的充要条件是gcd(a,m)=1，即a与m互质

// 费马小定理：设 𝑝 是质数．对于任意整数 𝑎 且 𝑝∤𝑎，都成立 𝑎^(𝑝−1) ≡ 1(mod 𝑝)
// 求解 a 模 p 的乘法逆元
// 如果 p 是质数，且a与p互质，依据费马小定理有 a^(p-1) ≡ 1(mod p)，即
// a*a^(p-2) ≡ 1(mod p)，因此a模p的乘法逆元为a^(p-2) mod p，用快速幂求解
// 如果a与p不互质，则逆元不存在

typedef long long ll;

ll Fast_Exponentiation(ll a,ll b,ll p)
{
    long long res=1 % p;
    // 这里要考虑p=1的情况，如果p=1，后续会变成累加，因此res需初始化为0
    while(b)
    {
        if(b & 1) // 按位与，得到b二进制最后一位
        {
            res = (res * a) % p;
        }
        a = a * a % p;
        b = b>>1;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        ll a,p; // 题目保证p为质数
        cin>>a>>p;
        if(a%p==0) cout<<"impossible"<<endl;
        else cout<<Fast_Exponentiation(a,p-2,p)<<endl;
    }
    return 0;
}


