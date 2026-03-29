#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];

// 选取数组中的一个数为基值，将数组一分为二，左侧数组的数均大于基值，右侧反之
// 在左侧数组选一个基值，将左侧数组一分为二，要求相同；对右侧数组同理
// 递归
void QuickSort(int a[],int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)>>1;
    int base=a[mid]; // 选取中间数为基值
    int i= l-1,j=r+1; // +1的原因后面会说明
    while(i<j)
    {
        // 这里需要注意一种情况，当a[i]=a[j]=base,i!=j，
        // 若使用如下方法移动指针会无限递归
        // while(a[i]<base) i++; 错误示范
        // while(a[j]>base) j--; 使用i++会使指针错指，故选择++i
        while(a[++i]<base); // 从左侧开始寻找大于等于base的数
        while(a[--j]>base); // 从右侧开始寻找小于等于base的数
        if(i<j) swap(a[i],a[j]);
    }
    // 举例说明，当数组为[1,2]时,l=0,r=1,mid=0,base=0
    // 划分后i=0,j=0，循环结束，如下写法会越界，
    // QuickSort(a,l,i-1);
    // QuickSort(a,i,r);
    // 故一般采用j为分界点
    QuickSort(a,l,j);
    QuickSort(a,j+1,r);
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
