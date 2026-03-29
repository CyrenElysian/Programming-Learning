#include <bits/stdc++.h>
using namespace std;

// 输出原序列中从第l个数到第r个数的和

const int N=1e5+10;
int num[N];
int prefix[N];

int main()
{
    int n,m; // n个整数,m次询问
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+num[i];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl; // 求l~r的和 前缀和数组下标
    }
    return 0;
}
