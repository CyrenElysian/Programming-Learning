#include <bits/stdc++.h>
using namespace std;

const int M=15; // 长度上限
const int N=1e3+10; // 询问次数/字符串上限
int n,m;
char str[N][M]; // 二维数组，用来存储多个字符串
int dp[M][M];

int edit_distance(char a[],char b[])
{
    int la= strlen(a+1);
    int lb= strlen(b+1);
    for(int i=0;i<=la;i++) dp[i][0]=i;
    for(int j=0;j<=lb;j++) dp[0][j]=j;

    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
        }
    }
    return dp[la][lb];
};

int main()
{
    cin>>n>>m; // n为字符串个数，m为询问次数
    for(int i=1;i<=n;i++)
        cin>>(str[i]+1); // 从数组下标1开始存储

    while(m--)
    {
        char s[M];
        int limit;
        cin>>(s+1)>>limit;

        int res=0;
        for(int i=1;i<=n;i++)
            if(edit_distance(str[i],s)<=limit)
                res++;
        cout<<res<<endl;
    }
    
    return 0;
}
