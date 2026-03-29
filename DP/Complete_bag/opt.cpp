// 已知：
//   f(i,j)=max (
//                 f(i-1,j)
//                 f(i-1,j-v_i)+w_i
//                 f(i-1,j-2*v_i)+w_i+w_i
//                 f(i-1,j-3*v_i)+2*w_i+w_i
//                 ...
//              )

// 同理可以推断：
// f(i,j-v_i)=max (
//                  f(i-1,j-v_i)
//                  f(i-1,j-2*v_i)+w_i
//                  f(i-1,j-3*v_i)+2*w_i
//                  ...
//                )

// 由于max函数的传递性，根据两式的相同部分，不难得到
// f(i,j)=max (
//              f(i-1,j)
//              f(i-1,j-v_i)+w_i
//            )

#include <iostream>
using namespace std;

int n,volume;
const int N=1e4+10;
int v[N],w[N];
int f[N][N];

int main()
{
    cin>>n>>volume;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=volume;j++)
        {
            if(v[i]<=j) f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i]);
            else f[i][j]=f[i-1][j];
        }
    }
    cout<<f[n][volume]<<endl;

    return 0;
}


