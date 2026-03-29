#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];
int r; // 右边界，初始等于n(堆元素数量)

void Adjust(int u) // 从最后一个非叶子结点开始，从右至左，从下至上进行调整，具体调整方式如下：
{
    int t=u; // 记录当前已知最小点的编号
    // 对于有n个节点的完全二叉树可以证明其前n/2(向下取整)节点必不是叶子节点，而大于n/2(向下取整)的必是叶子节点
    // 若完全二叉树某父节点i有左孩子和右孩子，其左孩子为2i，右孩子为2i+1
    if(2*u<=r && a[u]>a[2*u]) t=2*u; // 有左孩子，且左孩子值小于父节点
    if(2*u+1<=r && a[t]>a[2*u+1]) t=2*u+1; // 有右孩子，且右孩子最小
    if(u!=t)
    {
        swap(a[u],a[t]); // 如果父节点不是三者的最小值，与最小值交换
        Adjust(t); // 继续调整，直至数据结构为小根堆
    }

}


int main()
{
    int n,m;
    cin>>n>>m;
    r=n; // 初始有边界为n
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n/2;i>=1;i--) // 从最后一个非叶子结点开始，从右至左，从下至上进行调整
    {
        Adjust(i);
    }
    while(m--) // 每次循环输出堆顶.并将堆顶元素与右边界交换，调整右边界r=r-1
    {
        cout<<a[1]<<" ";
        swap(a[1],a[r]);
        r--;
        Adjust(1); // 调整堆
    }

    return 0;
}
