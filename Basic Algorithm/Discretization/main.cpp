#include <bits/stdc++.h>
using namespace std;

// 离散化:把无限空间中有限的个体映射到有限的空间中去，以此提高算法的时空效率。其基本思想就是在众多可能的情况中，只考虑需要用的值。
//原数据：1，999，100000，15；处理后：1，3，4，2；
//原数据：{100，200}，{20，50000}，{1，400}；处理后：{3，4}，{2，6}，{1，5}；

typedef pair<int, int> PII;

const int N = 3e5+10 ; // 开3e5+10的原因,1e5次对原x坐标位置数加c,而查询l和r各1e5次,
                       // 最坏情况下每个x,l,c均不同,即离散化后新坐标3e5个,即num[]最多3e5个元素

int n, m;
int num[N], prefix[N];
// num[]为离散化后的数组,prefix[]是对num[]求前缀和所得

vector<int> alls;
vector<PII> add, query;
// alls[]为所有要用到的坐标,包括原位置x和需要查询的l,r在后的坐标
// add[]中元素是(x,c),表示对原位置x上的数加c;query[]则为查询数组


int find(int x) // 二分查找 原位置x在all[]中的位置,其中alls[]中的坐标已经过排序和去重,结果返回就是x离散化后的坐标
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 返回 r+1 是因为前缀和数组是从1开始,而这里的alls[]是从0开始
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        alls.push_back(x);
    }

    for (int i = 0; i < m; i ++ )
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重,使原坐标(需要的x,l,r)与离散化的坐标是一一对应的
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    // unique()本质是将重复的元素移动到数组的末尾，最后再将迭代器指向第一个重复元素的下标。

    // 处理插入
    for (auto item : add)
    {
        int x = find(item.first); // 得到离散化后x的新坐标x'
        num[x] += item.second; // num[x']+c 
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i ++ ) prefix[i] = prefix[i - 1] + num[i];

    // 处理询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second); // 映射为离散化后的坐标
        cout << prefix[r] - prefix[l - 1] << endl;
    }

    return 0;
}

