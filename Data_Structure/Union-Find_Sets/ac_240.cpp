#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int p[N],d[N];
// 将话中相关联的动物放入一棵树，“树的棵数” 和 “动物种类数” 没有任何固定关系，可能远远多于 3 棵，也可能少于 3 棵
// p[i]表示节点i的父节点
// d[i] 初始表示 i 到其父节点 p[i] 的 相对距离，这里规定：
// 0: x与父节点是同类，1: x吃父节点，2: x被父节点吃

int find(int x)
{
    if (x!=p[x])
    {
        int t = find(p[x]); // 找到根节点
        d[x]+=d[p[x]]; // 计算x到根节点的实际距离
        p[x]=t; // 统一根节点
    }
    return p[x];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        d[i]=0;
    }
    int res=0; // 假话数量
    while(m--)
    {
        string op;
        int t,x,y;
        cin>>t>>x>>y;

        if(x>n || y>n) res++;
        else
        {
            int px=find(x);
            int py=find(y);
            if(t==1) // t=1,表述为x,y同类，若成立d[x]-d[y]=……，-3,0,3…… 即(d[x]-d[y])%3=0
            {
                if(px==py && (d[x]-d[y])%3 !=0) // 冲突：根节点相同(x,y相关，在同一棵树中)，但到根节点的距离差不是3的倍数
                {
                    res++;
                }
                else if(px!=py) // (x,y不相关，不在同一棵树中)合并两棵树，并设定它们之间的“相对种类”关系，使得新加入的那句话(x,y同类)成立
                {
                    p[px]=py; // 将px设置为py的“孩子”，这句话只在逻辑上正确，
                    // 实际上为了保证px挂到py上后，x和y到根节点的距离满足“同类”的判别条件，d[px]需要做调整，甚至d[px]可能为负数

                    d[px]=d[y]-d[x];
                    // 使“同类”这句话成立，推导过程如下：
                    // kind[]为0,1,2,0,1,2循环(1吃0,2吃1,0吃2)
                    // 当前两棵树互不相干，px、py 分别是两棵树的根，因此 kind[x] = kind[px] + d[x]和kind[y] = kind[py] + d[y]
                    // 要使合并后 kind[x] ≡ kind[y]，即kind[px] + d[x] ≡ kind[py] + d[y]，
                    // 即kind[px] - kind[py] = d[y] − d[x] (1)
                    // 把 px 挂到 py 下，即令kind[px] = kind[py] + d[px] (2)
                    // 联立(1)(2)可得
                }

            }
            else // t=2,表述为x吃y，若成立d[x]-d[y]=……，-2，1，……即(d[x]-d[y]-1)%3=0
            {
                if(px==py && (d[x]-d[y]-1)%3 != 0) // 冲突
                {
                    res++;
                }
                else if(px != py) // 合并两棵树，使得新加入的那句话(x吃y)成立
                {
                    p[px]=py;
                    d[px]=d[y]+1-d[x];
                    // 使x吃y这句话成立，推导过程如下
                    // 使“同类”这句话成立，推导过程如下：
                    // kind[]为0,1,2,0,1,2循环(1吃0,2吃1,0吃2)
                    // 当前两棵树互不相干，px、py 分别是两棵树的根，因此 kind[x] = kind[px] + d[x]和kind[y] = kind[py] + d[y]
                    // 要使合并后kind[x] ≡ kind[y] + 1,
                    // 即kind[px] − kind[py] ≡ d[y] + 1 − d[x] (1)
                    // 把 px 挂到 py 下，即令kind[px] = kind[py] + d[px] (2)
                    // 联立(1)(2)可得 d[px]=d[y]+1-d[x]
                }
            }
        }
    }

    cout<<res<<endl;

    return 0;
}