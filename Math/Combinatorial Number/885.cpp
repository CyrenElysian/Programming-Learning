#include <bits/stdc++.h>
using namespace std;
// 组合数公式 C(a,b)=C(a-1,b-1)+C(a-1,b)
// a个里面选b个，选择某人，还需在剩下的人中选b-1个；若不选，还需在剩下的人中选b个

const int N=2010,mod=1e9+7;
int c[N][N];

// 适用于a,b较小
void init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0) c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    init();
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<c[a][b]<<endl;
    }

    return 0;
}
