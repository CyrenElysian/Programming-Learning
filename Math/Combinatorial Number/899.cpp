#include <bits/stdc++.h>
using namespace std;

// 这个问题是经典的卡特兰数应用，问题以及公式已在图中给出
const int mod =1e9+7;
typedef long long ll;

int Fast_Exponentiation(int a,int k,int p) // 快速幂求解逆元
{
    int res = 1 % p;
    while (k)
    {
        if (k & 1) res = (ll) res * a % p;
        a = (ll) a * a % p;
        k = k >> 1;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int a=n*2,b=n; // 计算C(a,b)/(n+1) mod M
    int res=1;
    for(int i=a;i>a-b;i--) res=(ll)res*i % mod;
    for(int i=1;i<=b;i++)  res=ll(res)* Fast_Exponentiation(i,mod-2,mod)%mod;
    res=(ll)res* Fast_Exponentiation(n+1,mod-2,mod)%mod;
    cout<<res<<endl;
    return 0;
}