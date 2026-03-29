#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N];

void binary_search(int value)
{
    int l=0,r=n-1;
    // 左边界
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(a[mid]>=value) // 中间值大于等于value，左边界可能在更左边，缩小r
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }

    if(a[l]==value) // 找到左边界，再找右边界
    {
        cout<<l<<" ";
        l=0;r=n-1;
        while(l<r)
        {
            int mid=(l+r+1)>>1; // [2,4]查找2，如果不加1会无限循环
            if(a[mid]<=value)
            {
                l=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<r<<endl;
    }

    else
    {
        cout<<"-1 -1"<<endl;
    }
}

int main()
{
    cin>>n;
    int q;
    cin>>q;
    for(int i=0;i<n;i++) cin>>a[i];

    while (q--)
    {
        int k;
        cin>>k;
        binary_search(k);
    }

    return 0;
}