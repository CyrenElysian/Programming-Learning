# include <bits/stdc++.h>
using namespace std;

// 判断是否会产生回路的方法为：使用并查集
// 在初始状态下给各个个顶点在不同的集合。
// 遍历过程的每条边，判断这两个顶点的是否在一个集合中
// 如果边上的这两个顶点在一个集合中，说明两个顶点已经连通，这条边不要
// 如果不在一个集合中，则要这条边

const int N= 1e5+10,M=2e5+10;
struct Edge
{
    int u,v,w;
    // 重载小于运算符，使得两个Edge对象可以用 < 比较
    // operator< 是一个成员函数，用于重载 < 运算符
    // const Edge &e 表示右边的比较对象
    // 意思是，当前对象<e，指的是w<e.w
    bool operator<(const Edge &e)const
    {
        return w<e.w;
    }
}edges[M];

int p[N]; // 并查集,记录每个元素的父结点
int find(int x)
{
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x]; // 返回根结点
}

int n,m;
int res; // 记录权和
int cnt; // 记录最小生成树边数，与n-1作比较
// 执行算法前要对权边升序排列
void kruskal()
{
    for(int i=1;i<=m;i++) // 尝试依次加入每条边
    {
        int r_u=find(edges[i].u);
        int r_v=find(edges[i].v);
        if(r_u != r_v)
        {
           res+=edges[i].w;
           cnt++;
           p[r_u]=r_v; // 合并集合
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i; // 初始化并查集
    for(int i=1;i<=m;i++)
    {
        int x,y,weight;
        cin>>x>>y>>weight;
        edges[i]={x,y,weight};
    }

    sort(edges+1,edges+1+m); // 左闭右开
    kruskal();
    
    if(cnt<n-1) cout<<"impossible";
    else cout<<res;

    return 0;
}