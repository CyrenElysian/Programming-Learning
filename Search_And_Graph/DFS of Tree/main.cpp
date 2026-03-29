# include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int M=N*2; // 树是无环连通图，对于一个N结点的树，其边固定为N-1
// 无向图存储，空间扩大至2倍

int h[N],e[M],ne[M],idx;
bool state[N]; // 记录结点是否被访问过，避免重复访问
int ans=N; // 初始一个较大的数为答案
// 在这里介绍一种图的存储方式——链式前向星存储
// idx：索引
// e[i]：序号为i的边的终点的编号
// ne[i]：序号为i的边的下一条边的序号
// h[j]：以编号j结点为起点的第一条边的序号

// 利用链式前向星存储添加边
void add(int a,int b) // a,b分别为起点和终点编号
{
    e[idx]=b;

    ne[idx]=h[a]; // 新增边的邻边为起点
    h[a]=idx; //
    // 类似头插法，每次将新边插入表头，并将next指针指向上一次的“新边”
    idx++;
}


int n;
int dfs(int u) // 返回去除结点u后的最大连通块的最小值
{
    state[u]= true;
    int size=0; // size记录删除u后最大连通块大小
    int sum=0; // sum记录所有子树结点数之和，n-sum-1即是剩余部分结点数之和

    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(state[j]) continue; // 避免访问重复结点

        int s=dfs(j);  // 递归获取各个子树的大小
        size=max(s,size); // 取最大值
        sum = sum+s; // 累计所有子树的大小
    }
    size=max(size,n-sum-1);
    ans= min(ans,size);
    return sum+1;
}

int main()
{
    cin>>n;
    memset(h,-1, sizeof(h));
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a); // 无向图，需加两次
    }

    dfs(1);
    cout<<ans;
    
    return 0;
}