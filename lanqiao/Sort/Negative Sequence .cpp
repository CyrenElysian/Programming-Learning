#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int temp[N]; // 临时数组
typedef long long ll;
ll ans;

void merge_sort(int a[],int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)>>1;

    // 先分割
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);

    int idx=0;
    int i=l,j=mid+1; // 按顺序遍历两个有序数组a[l]~a[mid]与a[mid+1]~a[r]
    while(i<=mid && j<=r) // 按大小顺序存入临时数组
    {
        if(a[i]<=a[j]) temp[idx++]=a[i++];
        else
        {
            ans+=(mid-i)+1;
            // a[i]>a[j]，则a[i+1]~a[mid]均大于a[j]，贡献mid-i+1个逆序对
            temp[idx++]=a[j++];
        }
    }
    // 处理数组剩余
    while(i<=mid)
    {
        temp[idx++]=a[i++];
    }
    while(j<=r) temp[idx++]=a[j++];

    idx=0;
    for(int k=l;k<=r;k++) a[k]=temp[idx++]; // 存回原数组，返回一个有序数组
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    merge_sort(a,0,n-1);
    cout<<ans<<endl;
    return 0;
}