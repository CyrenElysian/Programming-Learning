#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;

// 约数和定理 N 的所有正约数之和等于 各个质因子能组成的约束和的乘积
// 例如：12=2*2*3 ，其所有正约数之和为(1+2+4)*(1+3)=(1+2+3+4+6+12)
// 可以观察到将N分解质因式后，从每个括号里选择一个因子组合相乘就能得到N的所有因子

bool Prime(int x)
{
    if (x<2) return false;
    if (x==2) return true;
    if (x%2==0) return false;
    for(int i=3;i<=x/i;i+=2)
    {
        if (x%i==0) return false;
    }
    return true;
}

unordered_map<int,int> num;
void factors(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(!Prime(i)) continue;
        while (x%i==0)
        {
            num[i]++;
            x/=i;
        }
    }
    if (x>1) num[x]++;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        factors(a);
    }

    // 这里介绍一种简单求解等比数列和的方法
    // 等比数列求和可以看作一个系数均为1的多项式，可以使用秦九韶算法
    // (((a+1)*a+1)*a+1)=a^3+a^2+a^1+1
    long long res=1;
    for(auto p:num)
    {
        long long a=p.first,b=p.second;
        long long t=1;
        while(b--)
            t=(t*a+1) % M; // 求局部的和，为避免和过大，应该提前取模
        res=res*t % M;
    }
    cout<<res;

    return 0;
}