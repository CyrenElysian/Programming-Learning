# include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII; // 存储坐标
const int N=110;
int graph[N][N];
int distance_[N][N];
int n,m;

void bfs(int x,int y)
{
    queue<PII> q;
    q.push({x,y});

    while(!q.empty()) // 队列不为空
    {
        PII start=q.front(); // 取队列中元素进行BFS，直到队列为空
        q.pop();
        graph[start.first][start.second]=1; // 限制反向探寻
        int dx[4]={0,0,-1,1}; // 上下左右四个方向
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int new_x=start.first+dx[i];
            int new_y=start.second+dy[i];
            if(graph[new_x][new_y]==0) // 可以走通
            {
                graph[new_x][new_y]=1; // 标记走过
                distance_[new_x][new_y]= distance_[start.first][start.second]+1;
                q.push({new_x,new_y}); // 入队，之后从该点探寻
            }
        }
    }
    cout<<distance_[n][m];
}

int main()
{
    cin>>n>>m;

    memset(graph, 1, sizeof(graph));
    // 初始化将graph全标记为1，而不是仅n*m范围
    // 若只初始化n*m，由于graph数组为N*N(N=110)，当探寻到迷宫边界(n*m)时，
    // 因为边界外的值为0，会探寻出迷宫，在逻辑上引发错误

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>graph[i][j];
        }
    }
    bfs(1,1);
    return 0;
}