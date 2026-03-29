#include <bits/stdc++.h>
using namespace std;

// 对于a,b较大，无法预处理阶乘，但模数较小的情况，可以使用Lucas定理（具体见图）
// 该定理将大组合数转化为若干个小组合数的乘积，每个小组合数的参数均小于/p，可以直接用预处理阶乘 + 逆元计算
typedef long long ll;

int Fast_Exponentiation(int a,int k,int p) // 快速幂求解逆元
{
    int res=1%p;
    while(k)
    {
        if(k&1) res = (ll) res * a % p;
        a=(ll)a * a % p;
        k=k>>1;
    }
    return res;
}

int small_combination(int a,int b,int p) // 计算a,b均小于p是的组合数
{
    if(b>a) return 0;
    int res=1;
    for(int i=1,j=a;i<=b;i++,j--) // 组合数=a*...(a-b+1)/b!
    {
        res = (ll) res * j % p;
        // 当b<p是，显然b与p互质，运用费马小定理求逆元
        res = (ll) res * Fast_Exponentiation(i,p-2,p)%p;
    }
    return res;
}

int lucas(ll a,ll b,int p)
{
    if (a<p && b<p) return small_combination(a,b,p);
    return (ll) small_combination(a%p,b%p,p)* lucas(a/p,b/p,p)%p;
}

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        ll a,b;
        int p;
        cin>>a>>b>>p;
        cout<<lucas(a,b,p)<<endl;
    }

    return 0;
}