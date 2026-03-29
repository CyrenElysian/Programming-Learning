#include <bits/stdc++.h>
using namespace std;

//
// 排序：将所有区间按左端点从小到大排序
// 贪心：设当前需要覆盖的起点为 start
// 在左端点<=start的所有区间中，选择右端点最大的区间
// 如果选取的区间的右端点<start，说明无法完全覆盖，输出-1
// 否则，用该区间覆盖一段，start跟新为该区间的右端点，计数加1,
// 重复贪心的过程，直到start>=t

const int N=1e5+10;
struct Range
{
    int l,r;
    bool operator<(const Range &w)const
    {
        return l<w.l;
    }
}range[N];

int main()
{
    int start,end;
    cin>>start>>end;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        range[i]={l,r};
    }
    sort(range,range+n);

    int res=0;
    bool success= false;
    // 除了符合条件的区间的最大右端点<=start这一种无法完全覆盖的情况返回-1之外
    // 还有一种是，最后一次成功更新start后，区间仍然没有达到end，但已经无区间可用，循环自然退出
    for(int i=0;i<n;i++)
    {
        int j=i;
        int r=-2e9;
        while(j<n && range[j].l<=start)
        // 首先在l<=start结点中搜索右端点最大的区间，不能写成<
        // 如果只在l<start中寻找，若找不到右区间>=start的区间就返回-1显然有问题
        // 因为可能存在左端点为l的区间
        {
            r=max(r,range[j].r);
            j++;
        }

        res++;
        if(r>=end)
        {
            success= true;
            break;
        }

        // 为什么是<，而不是<=，想象一种情况：目标区间为一个点start=end
        // 如果此时某区间的右端点刚好为该点，也就是满足r=start，应该是成功覆盖，不应该返回-1
        if(r<start)
        {
            res=-1;
            break;
        }

        start=r;
        i=j-1;
        // 直接更新i，避免重复查找无关区间
        // 下一轮开始时的j等于当前结束的j，保证了左端点<=start
    }
    if(!success) res=-1;
    cout<<res<<endl;
    return 0;
}