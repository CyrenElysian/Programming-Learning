#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;
int t[N];

// 这里值得说明的是，sort()中的比较器和priority_queue()中的比较器是不同的
// sort 按照比较函数返回 true 的顺序排列元素，
// 若cmp(a,b) 为true，则a会被放在b之前，因此 return a > b 会实现降序
// priority_queue 内部使用堆结构，其比较器定义的是优先级关系
// 若 cmp(a, b) 为 true，则 a 被认为优先级低于 b，即 b 应比 a 更靠近堆顶
// 因此 return a > b 会让较小的数优先级更高，实现小顶堆

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>t[i];

    sort(t,t+n); // sort默认升序
    reverse(t,t+n);
    
    ll res=0;
    for(int i=0;i<n;i++)
    {
        res+=t[i]*i;
    }
    cout<<res<<endl;
    return 0;
}
