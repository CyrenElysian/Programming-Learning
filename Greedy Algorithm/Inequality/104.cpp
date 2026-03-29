#include <bits/stdc++.h>
using namespace std;

// 距离和函数证明见图
// 绝对值函数是凸函数可以用绝对值不等式结合凸函数定义证明
// 简而言之，f(x)在点x的导数等于其 左边点的数量 - 右边点的数量
// 故导数为0的点在左右点的数量相同时
// 设点数量为n，若n为奇数，导数为0的点唯一
// 若n为偶数，在最中间两点的闭区间上均为0

const int N=1e5+10;
int a[N];
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    ll res=0;
    int median=a[n/2];
    for(int i=0;i<n;i++)
        res+=abs(a[i]-median);

    cout<<res<<endl;
    return 0;
}