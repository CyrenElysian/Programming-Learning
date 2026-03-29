#include <bits/stdc++.h>
using namespace std;

const int N=6e3+10;
int happy[N]; // 快乐指数
int f[N][2];
// f[u][0]表示如果不选u号节点，所有以u为根的子树的快乐指数之和的最大值
// f[u][1]表示如果选则u号节点，所有以u为根的子树的快乐指数之和的最大值

int e[N],ne[N],h[N],idx;
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void dfs(int u)  // u为根节点
// 自底向上计算出每个节点在选与不选两种情况下的最优快乐值，最终为整棵树提供答案
{
    f[u][1]=happy[u]; //初始化，f[u][0]已初始化为0
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        dfs(j);

        f[u][0]+=max(f[j][0],f[j][1]);
        // 不选根节点，那么其子节点可选可不选
        f[u][1]+=f[j][0];
    }
}

bool has_father[N]; // 记录每个节点是否有父节点
// 需要寻找根节点


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>happy[i];
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++)
    {
        int low,up; // up是上司，low是下属
        cin>>low>>up;
        has_father[low]= true;
        add(up,low);
    }

    int root=1;
    while(has_father[root]) root++; // 寻找树的根节点
    dfs(root);
    cout<<max(f[root][0],f[root][1])<<endl;

    return 0;
}
