#include <bits/stdc++.h>
using namespace std;

// 对于a,b≤5000的组合数，直接计算阶乘会溢出，
// 因此采用质因数分解 + 高精度乘法的方法，组合数的质因数分解见图

const int N=5010;
int  primes[N],cnt; // 存储所有质因子，cnt为填充数组的记号
int sum[N]; // sum[i]存储第i个质因子在C(a,b)中的质数，转而变为求和形式
bool st[N]; // 表示st[i]是否为合数

void get_primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]= true;
            if(i % primes[j]==0) break;
            // break原因见图
        }
    }
}

int get_factors_exponential(int n,int p) // 计算阶乘中质因子指数
// 组合数的质因数分解以及各质因数的指数获取原理见图
{
    int res=0;
    while(n)
    // 循环不断除以 p 并累加商，即可得到指数
    {
        res+=n/p;
        n/=p;
    }
    return res;
}

vector<int> mul(vector<int>a,int b)
// 计算大整数a与小整数b的乘积，a用来保留每次
{
    vector<int> c; // 存储结果的数组
    int t=0; // 进位
    for(int i=0;i<a.size();i++)
    {
        t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(t)
    {
        c.push_back(t%10);
        t/=10;
    }
    return c;
}
// eg:123*45
// i    a[i]    t初始    t+=a[i]*b   t新值    c.pushback(t%10)   t/=10
// 0     3        0     0+3*45=135   135            5             13
// 1     2       13     13+2*45=103  103            3             10
// 2     1       10     10+1*45=55    55            5              5
// 退出循环，t=5，最后结果为5535
int main()
{
    int a,b;
    cin>>a>>b;

    get_primes(a);
    for(int i=0;i<cnt;i++)
    {
        int p=primes[i];
        sum[i]= get_factors_exponential(a,p)
                - get_factors_exponential(b,p)
                - get_factors_exponential(a-b,p);
    }

    vector<int> res;
    res.push_back(1); // 初始化res=1

    for (int i=0;i<cnt;i++)
    {
        for(int j=0;j<sum[i];j++)
        {
            res=mul(res,primes[i]);
        }
    }
    for(int i=res.size()-1;i>=0;i--) // 逆序输出正确结果
        cout<<res[i];
    cout<<endl;

    return 0;
}