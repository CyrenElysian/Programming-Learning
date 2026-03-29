#include <bits/stdc++.h>
using namespace std;

// 将所有区间按左端点排序
// 存储每个区间组最右端点的值
// 遍历区间，如果当前区间的左端点大于某区间组的最右端点，说明当前区间可以进入该区间组
// 否则，需要新开一个区间组
// 在区间分组问题中，当遍历到一个区间时，可能会有多个已有的组都满足“当前区间的左端点大于该组的右端点”
// 此时我们采用贪心策略(这是经典做法，具体怎么放好像不影响)，选择右端点最小的组，这是因为：
// 因为区间是按左端点排序的，后面处理的区间左端点只会更大，
// 如果我们在当前时刻复用了一个右端点较大的组，那么保留下来的是右端点更小的组
// 后续区间要想复用某个组，需要它的左端点大于该组的右端点
// 保留更小的右端点，意味着后续区间更容易满足条件，从而减少新开组的次数
// 为了方便获取所有区间组中右端点的最小值，我们可以维护一个小根堆

const int N=1e5+10;
struct Range
{
    int l,r;
    bool operator< (const Range &w)const
    {
        return l<w.l;
    }
}range[N];

struct cmp
{
    bool operator()(int a,int b)const
    {
        return a>b; // a>b 为 true时，a的优先级更低，排在后面
    }
};



int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        range[i]={l,r};
    }
    sort(range,range+n);

    priority_queue<int,vector<int>,cmp>heap; // 小根堆
    for(int i=0;i<n;i++)
    {
        auto interval =range[i];
        if(heap.empty() || interval.l<=heap.top())
        // 如果堆为空：暂时没有区间组
        // 当前区间的左端点，小于等于所有区间组的右端点
        // 两种情况都需要开新的区间组
        {
            heap.push(interval.r);
        }
        else
        // 否则，加入右端点最小的区间组，并更新小根堆
        {
            heap.pop();
            heap.push(interval.r);
        }
    }
    // 最终小根堆的大小即使组数
    cout<<heap.size()<<endl;
    return 0;
}