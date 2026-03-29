#include <bits/stdc++.h>
using namespace std;

// 辗转相减法求最大公约数
// 两个数的最大公约数等于它们的差与较小数的最大公约数
// 用(a,b)表示a,b(a>=b)的最大公约数，则有(a,b)=(a-b,b)
// (48,18)=(30,18)=(12,18)=(12,6)=(6,6)=6
// 证明：设d=gcd(a,b)(a>=b)，则存在正整数m,n，使得a=md，b=nd，gcd(m,n)=1;
// a-b=(m-n)d，b=nd，故要证明gcd(b,a-b)=d，只需证明gcd(n,m-n)=1
// 假设存在质数p，使得n%p=0 且 (m-n)%p=0
// 由于p能整除n，又能整除m-n，所以必能整除m，这与前提gcd(m,n)=1矛盾
// 故假设不成立，gcd(n,m-n)=1，即gcd(b,a-b)=d，即(a,b)=(b,a-b)

// 对辗转向减法优化可以得到辗转相除法（欧几里得算法）

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int a,b;
        cin>>a>>b;
        while(b!=0)
        // 不可以写成a!=b，当a=4且b=2时，经过一轮循环a=2，b=0，依然会执行下去
        {
            int c=a%b; // 如果a<b,c=a；如果a>b，c=a-b-b-...直至c<b
            a=b;
            b=c;
        }
        cout<<a<<endl;
    }
    return 0;
}