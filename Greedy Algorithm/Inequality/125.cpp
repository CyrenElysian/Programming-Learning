#include <bits/stdc++.h>
using namespace std;

// 将(w+s)进行排序，小点在上，大的在下，相关证明见图

const int N=5e4+10;
typedef pair<int,int> PII;
PII cows[N];

struct cmp
{
    bool operator()(PII a,PII b)
    {
        return  a.first+a.second<b.first+b.second;
    }
};

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int w,s;
        cin>>w>>s;
        cows[i]={w,s};
    }
    sort(cows,cows+n,cmp());

    long long ans=-1e11; // 初始化风险值（可能为负）
    long long sum=0; // 初始化当前牛上面的总重量
    // 从上到下遍历牛
    for(int i=0;i<n;i++) //
    {
        long long risk= sum-cows[i].second;
        if(risk>ans) ans=risk;
        sum+=cows[i].first;
    }
    cout<<ans<<endl;
    return 0;
}