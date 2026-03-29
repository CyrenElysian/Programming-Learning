#include <bits/stdc++.h>
using namespace std;

// 同905思路
// 将区间按右端点排序
// 遍历区间，如果该区间不包含上一次选的点，就选取该区间的右端点，否则跳过

const int N=1e5+10;
struct Range
{
    int l,r;
    bool operator< (const Range &w)const // 重载运算符<
    {
        return r<w.r;
    }
}range[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) cin>>range[i].l>>range[i].r;
    sort(range,range+n); // 默认升序，<运算符已重载

    int res=0;
    int end=-(1e9+10);
    for(int i=0;i<n;i++)
    {
        if(range[i].l>end)
        {
            res++;
            end=range[i].r;
        }
    }
    cout<<res<<endl;

    return 0;
}
