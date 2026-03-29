#include <bits/stdc++.h>
using namespace std;

// 模运算有以下性质：
// (a+b)%p=(a%p+b%p)%p，该性质对于加减乘成立，但对于除法不成立
// 在a,b较大的情况下，直接运算组合数会溢出，通常题目会要求取余，但是除法又不满足该性质
// 在模 M 移一下，不能直接做除法，需要用乘法逆元
// 算法的推导思路见图

const int N=1e5+10,mod =1e9+7;
int fact[N]; // 存储阶乘
int infact[N]; // 存储阶乘的逆元

typedef long long ll;
int Fast_Exponentiation(int a,int k,int p) // 快速幂求解逆元
{
    int res=1%p;
    while(k)
    {
        if(k&1) res = (ll)res * a % p;
        a=(ll)a * a % p;
        k=k>>1;
    }
    return res;
}

int main()
{
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(ll)fact[i-1]*i % mod;
        infact[i]=(ll)infact[i-1]* Fast_Exponentiation(i,mod-2,mod)%mod;
        // infact[i-1]=infact[i]*i，i的逆元可以为(i^(mod-2))%mod
    }

    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<(ll)fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
    }
    return 0;
}