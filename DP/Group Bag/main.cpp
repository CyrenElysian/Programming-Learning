#include <bits/stdc++.h>
using namespace std;

const int N=110;
int volume[N][N],value[N][N],s[N];
// volume[i][j]表示第i组第j物品的提起，value表示价值，s[i]表示第i组物品数量
int f[N];
int n,v; // 物品总类数与背包容量

int main()
{
    cin>>n>>v;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=1;j<=s[i];j++)
            cin>>volume[i][j]>>value[i][j];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=v;j>=0;j--)
        {
            for(int k=1;k<=s[i];k++)
            {
                if(volume[i][k]<=j)
                    f[j]=max(f[j],f[j-volume[i][k]]+value[i][k]);
            }
        }
    }

    cout<<f[v]<<endl;

    return 0;
}
