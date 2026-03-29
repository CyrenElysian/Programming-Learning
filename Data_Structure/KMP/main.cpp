#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10,M=1e6+10;

int n,m;
int ne[N];
char s[M],p[N];

int main()
{
    cin>>n>>p+1>>m>>s+1;

    // 求next[]过程与匹配过程类似
    for(int i=2,j=0;i<=n;i++)
    // i指向当前正在计算next值的位置
    // j记录当前已匹配的 最长公共前后缀 长度
    // i从第二位开始，因为next[1]=0必然成立，j初始设置为0（初始长度为0），每次检查p[i]=p[j+1]是否成立
    // 如果成立，第i位的最长公共前后缀长度加1(j=j+1)，令next[i]=j，指针i右移，再检查p[i]=p[j+1]，重复此过程
    // 如果不成立，则要对j进行回溯，回溯至
    {

        while(j!=0 && p[i]!=p[j+1]) // 当前字符不匹配
        {
            j=ne[j];
        }

        if(p[i]==p[j+1])
        {
            j++; // 如果匹配成功，最长公共前后缀加1
        }
        ne[i]=j;
    }

    // P匹配S
    for(int i=1,j=0;i<=m;i++)
    {
        while(j!=0 && s[i]!=p[j+1])
        {
            j=ne[j];
        }
        if(s[i]==p[j+1])
        {
            j++;
        }
        if(j==n)
        {
            cout<<i-n+1<<" "; // 题目若要求数组从0开始就是i-n，这里按照从1开始故为i-n+1
            j=ne[j]; // 之所以j回溯到next[j]而不是从P[1]开始检查匹配，是因为s[i-n+1,i]中的后next[j]项与p[1,next[j]]匹配(最长公共前后缀)
                     // 故接下来只要从s[i+1]和p[next[j]+1]开始检查匹配即可
        }
    }
    return 0;
}
