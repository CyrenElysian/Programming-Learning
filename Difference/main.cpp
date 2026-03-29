#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int num[N];
int diff[N];

// 差分数组可以用来将序列中 [l,r]之间的每个数加上 c

int main()
{
    int n,m;
    cin>>n>>m; // n个整数,m次操作
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    for(int i=1;i<=n;i++)
    {
        diff[i]=num[i]-num[i-1];
    }
    // diff[i]+c,相当于原数组num[]编号为i之后的所有数都加上了c
    // 若对diff[l]+c,diff[r+1]-c，相当于对原数组num[]编号为l~r的所有数都加上了c
    for(int i=1;i<=m;i++)
    {
        int l,r,c;
        cin>>l>>r>>c;
        diff[l]+=c;
        diff[r+1]-=c;
    }

    for(int i=1;i<=n;i++)
    {
         diff[i]=diff[i]+diff[i-1]; //用差分数组还原现在的num[]数组
         cout<<diff[i]<<' ';
    }

    return 0;
}
