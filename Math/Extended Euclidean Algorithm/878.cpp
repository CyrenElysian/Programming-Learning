#include <bits/stdc++.h>
using namespace std;

// 给定a,b,m，求解同余方程 ax≡b (mod m)
// 同余方程等价于存在整数y，使得 ax+my=b，类比扩展欧几里得算法问题
// 设d=gcd(a,m)，方程ax+my=b有整数解，当且仅当d|b(b%d=0)，具体证明见图
// 因此，若d|b，可以先用扩展欧几里得求出ax'+my'=d的一组解(x',y')
// a*(b/d)x'+m*(b/d)y'=(b/d)d=b
// 所有原方程的一个特解为x=x'*(b/d)，进而原方程的通解（见图）
// 

typedef long long ll;

int ex_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int d= ex_gcd(b,a%b,y,x);
    y=y-a/b*x;
    return d;
}

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int a,b,m;
        cin>>a>>b>>m;

        int x,y;
        // 解ax+my=b，注意参数对齐
        int d= ex_gcd(a,m,x,y);
        if(b%d != 0) cout<<"impossible"<<endl;
        else cout<<(ll)b/d*x%m<<endl;
        // 将b强制转换成long long 类型，这样做是为了防止整数乘法溢出
        // 根据同余的性质：如果x是ax≡b(mod m)的一个解，那么任何与x模m同余的数也是解
    }
    return 0;
}