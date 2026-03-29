#include <bits/stdc++.h>
using namespace std;

// 另一种简单的想法

const int N = 1e6+10;
int a[N];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];//读入数据

    deque<int> q;
    // 处理最小值
    // 对于最小值，如果当前的滑动窗口中有两个下标i、j(i<j)，如果a[j]<a[i]，那么只要a[j]存在，最小值就不会输出为a[i]，
    // 且因a[j]在a[i]的右边，所以可以删除a[i]
    // 即只要新元素比队尾元素小，弹出队尾元素，让新元素入队
    // 队列最终为递增序列
    for(int i = 1; i <= n; i++)
    {
        while(q.size() && q.back() > a[i]) // 新进入窗口的值小于队尾元素，则队尾出队列
            q.pop_back();
        q.push_back(a[i]); // 将新进入的元素入队

        if(i>=k)
        {
            if(i - k >= 1 && q.front() == a[i - k])
            {
                q.pop_front();
            }
            cout << q.front() <<" ";
        }
    }

    q.clear();
    cout << endl;

    // 处理最大值
    // 对于最大值，如果当前的滑动窗口中有两个下标i、j(i<j)，如果a[j]>a[i]，那么只要a[j]存在，最大值就不会输出为a[i]，
    // 且因a[j]在a[i]的右边，所以可以删除a[i]
    // 即只要新元素比队尾元素大，弹出队尾元素，让新元素入队
    // 队列最终为递减序列
    for(int i = 1; i <= n; i++)
    {
        while(q.size() && q.back() < a[i]) q.pop_back();
        q.push_back(a[i]);
        if(i>=k)
        {
            if(i - k >= 1 && q.front() == a[i - k])
            {
                q.pop_front();
            }
            cout << q.front() <<" ";
        }
    }
}

