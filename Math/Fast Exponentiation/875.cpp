#include <bits/stdc++.h>
using namespace std;

// 要求a^b mod p ，如果直接乘方取模，时间复杂度为O(b)
// 快速幂是一种将时间复杂度降低到O(logb)的算法，具体推导见图
// 首先，将指数b表示成二进制形式：(b_k)...(b2)(b1)(b0)
// 即b=(b_k)*2^k+...+(b_1)*2^1+(b_0)*2^0
// 计算过程中，初始res=1，维护当前底数base（初始为a)，如果b的二进制末位为1
// res=(res*base) mod p，更新base=((base)^2) mod p，b右移一位

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

    while(n--)
    {
        ll a,b,p;
        cin>>a>>b>>p;
        cout<<Fast_Exponentiation(a,b,p)<<endl;
    }
    
    return 0;
}
