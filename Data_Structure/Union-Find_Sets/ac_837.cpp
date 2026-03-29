#include <bits/stdc++.h>
using namespace std;

// 连通块是图论中的一个重要概念，指的是在一个图中，任意两个节点之间都有路径相连的节点集合。
const int N=1e5+10;

int p[N],amount[N];
// p[i]表示节点i的父节点，amount[i]表示节点i所在连通块的节点数(特别强调：当且仅当i为根节点时,amount[i]有意义)

int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        amount[i]=1;
    }

    while(m--)
    {
        string op;
        cin>>op;
        if(op=="C")
        {
            int a,b;
            cin>>a>>b;
            if(find(p[a]) == find(p[b]))
            {
                continue; // 如果节点编号相同，跳出此次循环，不执行amount自加操作
            }
            amount[find(b)] += amount[find(a)];
            p[find(a)]=find(b);
        }
        else if(op=="Q1")
        {
            int a,b;
            cin>>a>>b;
            if(find(a)==find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else
        {
            int a;
            cin>>a;
            cout<<amount[find(a)]<<endl;
        }
    }

    return 0;
}