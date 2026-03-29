#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int h[N],e[N],ne[N],idx; // 详见 DFS of Tree
int dist[N];  // 记录距离
bool state[N];

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

void bfs()
{
    memset(dist,0x3f,sizeof(dist)); // 初始距离不可达
    dist[1]=0;
    queue<int> q;
    q.push(1);
    state[1]= true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int i=h[temp];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(!state[j])
            {
                dist[j]=dist[temp]+1;
                q.push(j);
                state[j]= true;
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    // void *memset(void *s, int c, size_t n)
    // memset 将 c 的低 8 位复制到从 s 开始的连续 n 个字节中
    // 因此，它按字节操作，而非按元素类型操作
    // memset(arr, 0, sizeof(arr));   全部字节置0
    // memset(arr, -1, sizeof(arr));  每个字节为 0xFF，补码表示 -1
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }

    bfs();
    cout<<(dist[n] == 0x3f3f3f3f ? -1 : dist[n]) <<endl;

    return 0;
}