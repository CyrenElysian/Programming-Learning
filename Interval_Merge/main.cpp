#include <bits/stdc++.h>
using namespace std;

// 区间合并 先将所有区间按照左端点大小排序,按顺序读取每个区间,该新区间与已有区间有共同部分则合并,否则开辟一个新的大区间。

typedef pair<int,int> PII;
vector<PII> seg;

void merge(vector<PII> &seg)
{
    vector<PII> res;
    sort(seg.begin(),seg.end());

    int st=-1e9-1; // 赋值一个题目范围外的数
    int ed=-1e9-1;
    for(auto i : seg)
    {
        if(i.first>ed) // 如果新区间的左端点值大于已有区间的右端点值,则已有区间已达到最大,需要开辟新区间。
        {
            if(st != -1e9-1)
            {
                res.push_back({st,ed}); // 将已有区间 push 进 res
            }
            st=i.first; // 获得新区间的左右端点
            ed=i.second;
        }
        else
        {
            ed=max(ed,i.second); // 若有公共部分则合并
        }
    }
    // 结尾情况:若最后一个区间和已有区间有公共部分,则合并(执行else);若无公共部分,push已有区间(执行if),赋值新的st和ed
    // 故无论如何都要在循环结束后再push一次
    res.push_back({st,ed}); // push最后一个区间
    seg = res;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        seg.push_back({l,r});
    }
    merge(seg);
    cout<<seg.size()<<endl;
    return 0;
}
