#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int num[N];
int a[N],b[N];


int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    for(int i=1,j=m;i<=n;i++)
    {
        while(j>0 && a[i]+b[j]>x)
        {
            j--;
        }
        if(a[i]+b[j]==x)
        {
            cout<<i<<' '<<j<<endl;
            break;
        }
    }
    return 0;
}
