#include <bits/stdc++.h>
using namespace std;

// 扩展欧几里得算法是在欧几里得算法的基础上扩展，不仅能计算最大公约数gcd(a,b)
// 还能找到一组整数解(x,y)使得 ax+by=gcd(a,b)，算法原理如下
// 设d=gcd(a,b)=gcd(b,a mod b)，其中 a mod b=a−⌊a/b⌋⋅b
// 设(x',y')是方程 bx+(a mod b)y=d 的一组解：
// bx'+(a mod b)*y'=d，将a mod b=a−⌊a/b⌋b带入得：
// bx′+(a−⌊a/b⌋b)y′=d，整理得ay'+b(x'-⌊a/b⌋y']=d
// 对比原方程 ax+by=d，可以得到原方程的一组解x=y'，y=x'-⌊a/b⌋y'
// 因此可以通过递归寻找最终解，递归边界为
// 当b=0是，gcd(a,0)=a，方程a*x+0*y=a，解为x=1,y=0

// 预找 ax+by=d 的解(x,y)，需先找 bx'+(a mod b)*y'=d 的解(x',y')，
// 递推公式为x=y'，y=x'-⌊a/b⌋y'
// 扩展欧几里得算法，返回 gcd(a,b)，并求出 x,y 满足 ax+by=gcd
int ex_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    // 如果b不为0，转而求解子问题的解(x',y')
    // 递推公式为x=y'，y=x'-⌊a/b⌋y'
    // 子问题求解x'和y'，返回y=x'，x=y'
    // x已经正确，需要修正y的值：y=x'-⌊a/b⌋y'=y-a/b*x
    int d = ex_gcd(b,a%b,y,x);
    y = y - a/b * x;
    return d;
}

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int a,b;
        cin>>a>>b;
        int x,y;
        ex_gcd(a,b,x,y);
        cout<<x<<" "<<y<<endl;
    }

    return 0;
}
