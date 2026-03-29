#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int p[N]; // p[i]存储元素i的父节点

// 合并集合
// 将元素a所在的集合直接挂在元素b所在树的根结点下

// 若满足p[x]=x，则x为根节点(因为在合并集合过程中，如将a集合插入b集合，a树的根节点的父节点会变为b树的根节点，而不再是它自身)
int find_root(int x) // 递归找到元素x所在集合的根节点
{
    // 如果p[x]=x，x即为根节点，返回；若p[x]!=x，x不是根节点，查看x父节点p[x]是否为根节点，
    // 若是将其集合编号(即p[p[x]])赋予p[x]，若不是，重复以上过程，直至找出根节点

    // 核心优化：路径压缩，这是一个优化过程，将集合中元素的父节点统一更新为根节点，
    // 因为根节点只有一个，在查询两元素是否在同一个集合中可将速率提升至O(1)
    if(p[x]!=x) p[x]=find_root(p[x]);
    return p[x];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i; // 初始化，每个元素都是一个独立的集合，它的父节点就是它自己，也就是每个元素都是自己所在集合的根节点
    }

    while(m--)
    {
        char op;
        int a,b;
        cin>>op>>a>>b;
        if(op=='M')
        {
            p[find_root(a)]=find_root(b);
            // 查找a、b所在树的根节点，将a树根节点的父节点改为b树的根节点，即a树的根节点作为b树根节点的子节点，这样a,b就在同一棵集合树中了
        }
        else
        {
            if(find_root(a)== find_root(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }

    return 0;
}
