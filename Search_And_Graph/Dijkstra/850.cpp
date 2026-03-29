# include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII; // 存储 (距离，结点编号)对
const int N=1e6;

int n,m;
int h[N],e[N],ne[N],w[N],idx;
int dist[N]; // 存储起点到各个结点的距离
bool state[N];

struct compare  // 实际上等于 greater 模版（重构 >）
{
    bool operator()(PII a,PII b) // 接收两个参数a,b
    {
        return a.first>b.first;
    }
};
// 当一个类（或结构体）重载了 operator()
// 该类的对象就可以像普通函数一样被调用，这样的对象称为函数对象
// compare cmp; bool result = cmp(3, 5); cout << result; 输出0

// C++ 的 priority_queue 比较器（Compare）的作用是定义元素的优先级顺序
// 它的语义是：如果比较器 cmp(a, b) 返回 true，则意味着 a 的优先级低于 b
// 因此 b 应该出现在 a 的前面（即 b 更接近队首/堆顶）
// 换句话说，比较器定义的是弱顺序中的“小于”关系，即“优先级更低”


void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}

int Dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    // 不可标记state[1]= true，
    // 导致从起点出发的边无法被松弛，因为算法认为起点已经“确定”了
    priority_queue<PII, vector<PII>, compare> heap;
    heap.push({0,1});

    while(!heap.empty())
    {
        auto t=heap.top(); // 直接获取堆顶元素（小根堆）
        heap.pop();

        int index= t.second;
        int distance= t.first;

        if (state[index]) continue;
        state[index]= true;

        for(int i=h[index];i!=-1;i=ne[i]) // 更新距离
        // 从t.second点出发开始探寻，看经过该点到其它点的距离能否缩短
        {
            int j=e[i];
            if (dist[j]>dist[index]+w[i])
            {
                dist[j]=dist[index]+w[i];
                heap.push({dist[j],j});
            }
        }
    }

    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin>>n>>m;
    memset(h,-1, sizeof (h));
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<Dijkstra()<<endl;
    return 0;
}

// 算法的核心思想是每次从队列中取出当前距离最小的节点，并认为这个节点的最短距离已经最终确定
// （因为所有边权非负，不可能通过其他节点绕路得到更短的距离）
// 然后利用这个节点去尝试更新它的邻居节点，如果邻居的距离变小了，就将其加入队列（或更新其在队列中的优先级）
// 当优先队列为空时，说明已经没有“待确定”的节点了。这意味着：
// 所有从源点可达的节点都已经被取出并处理过，它们的最短距离已经确定。
// 那些从未被加入队列的节点，说明源点无法到达它们，因此它们的距离保持初始的无穷大
//（因为如果能到达，总会在某次松弛中被加入队列）