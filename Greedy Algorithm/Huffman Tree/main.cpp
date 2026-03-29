#include <bits/stdc++.h>
using namespace std;

// 注意哈夫曼树与区间DP的异同
// 区间DP受限于区间连续性，只能合并相邻堆；哈夫曼树任意两堆均可合并，无位置限制

struct cmp
{
    bool operator()(int a,int b)const
    {
        return a>b;
    }
};

int main()
{
    int n;
    cin>>n;

    priority_queue<int,vector<int>,cmp>heap;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        heap.push(a);
    }

    long long total_cost=0;
    while(heap.size()>1)
    {
        int first=heap.top();
        heap.pop();
        int second=heap.top();
        heap.pop();

        int merge=first+second;
        total_cost+=merge;

        heap.push(merge);
    }
    cout<<total_cost<<endl;
    return 0;
}