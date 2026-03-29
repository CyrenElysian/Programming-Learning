# include <bits/stdc++.h>
using namespace std;

// 这里用string字符串类，

int bfs(string start)
{
    string end="12345678x"; // 终态
    queue<string> q;
    unordered_map<string,int> d; // 存储键值对，状态：初态到现态的距离

    // 从初态探寻
    q.push(start);
    // 初始化初态距离为0
    d[start]=0;
    // 方向
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};

    while (!q.empty())
    {
        auto temp=q.front();
        q.pop();
        int distance = d[temp]; // 获取当前状态的距离

        if (temp==end)
        {
            return distance;
        }

        int pos=temp.find('x');
        // 寻找 x 的坐标，实际上是一个数值，将其转换为3*3的坐标系下的坐标：
        int x=pos/3 , y=pos%3;

        for(int i=0;i<4;i++)
        {
            int a=x+dx[i];
            int b=y+dy[i];
            if(a>=0 && a<3 && b>=0 && b<3) // 防止越界
            {
                swap(temp[pos],temp[a*3+b]); // 换位
                // count（） 成员函数用于统计容器中具有指定键的元素个数
                if(d.count(temp)==0) // 如果当前状态是第一次出现
                {
                    d[temp]=distance+1; // 距离+1，入队
                    q.push(temp);
                }
                swap(temp[pos],temp[a*3+b]); // 还原状态
            }
        }
    }

    return -1;
}

int main()
{
    string s,start;
    for(int i=0;i<9;i++)
    {
        cin>>s;
        start+=s;
    }
    cout<<bfs(start)<<endl;

    return 0;
}