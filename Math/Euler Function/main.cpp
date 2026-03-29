#include <bits/stdc++.h>
using namespace std;

// 欧拉函数E(n)是定义在正整数n上的函数，表示小于或等于n的正整数中与n互质的数的个数
// 1.若n为质数p，则E(p)=p-1，与除了自己的数都互质
// 2.若n=p^k，其中p为质数，则N(p^k)=p^k-p^(k-1)，即能被p整除的数只有p,2p,...,(p^(k-1))*p
// 3.欧拉函数式积性函数：若m,n互质，E(mn)=E(m)E(n)
// 对于任意正整数n，我们可以将其质因数分解n=p1^e1 * p2^e2 * ... p1,p2为不同的质数
// 利用欧拉函数的积性性质：E(n)=E(p1^e1) * E(p2^e2)* ...
// 进一步简化：E(n)=(p1^e1-p1^(e1-1)) * (p2^e2-p2^(e2-1))
// 提取一个因子n：E(n)=n * (1-1/p1) * (1-1/p2) * ...
// 也就是说，只要找到n的所有质因子即可求出E(n)


int main()
{
     int m;
     cin>>m;

     while(m--)
     {
         int n;
         cin>>n;
         int res=n;
         for(int i=2;i<=n/i;i++)
         {
             if(n%i==0) // 找到因子（后续会与操作保证其为质因子）
             {
                 // 1/i 可能除不尽，这里进行转换
                 // 1-1/i= (i-1)/i
                 // 为了有效避免较大数值溢出，可采用先除后乘的策略
                 res=res/i*(i-1);

                 while(n%i==0) n=n/i; // 对n进行约分
             }
         }
         if(n>1) res=res/n*(n-1);
         cout<<res<<endl;
     }

    return 0;
}
