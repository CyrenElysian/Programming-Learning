#include <iostream>
#include <deque>
using namespace std;

const int N=1e6+10;
int a[N];
deque<int>Q;

int main()
{
    int n,m;//n为元素个数，m为窗口大小
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    //以下操作是将数组元素的序号入队
    for(int i=1;i<=n;i++)
    {
        while(!Q.empty() && a[Q.back()]>a[i])
            //back()和front()传回的是队尾和队首元素的引用
            //如果队列不为空，且队尾元素大于将要进队的元素，则序号出队，保证队列Q对应的元素为单调递增序列
        {
            Q.pop_back();
        }
        Q.push_back(i);//序号入队

        if(i>=m)
            //如果队尾序号大于窗口大小，且队尾元素的序号i 减 队头元素的序号Q.front 大于等于m时，
            //说明此时队列中超过m个元素，此时队头元素出队
            //如1,2……，m(设对应元素序列单调递增)，此时窗口刚好满，m+1对应的元素最大，此时序号1就要出队
        {
            while(!Q.empty() && i-Q.front()>=m)
            {
                Q.pop_front();
            }
            cout<<a[Q.front()]<<" ";//单调递增序列，队头元素为最小值
        }
    }

    cout<<endl;

    while(!Q.empty())//清空队列
    {
        Q.pop_front();
    }
    for(int i=1;i<=n;i++)
    {
        while(!Q.empty() && a[Q.back()]<a[i])//保证Q为单调递减序列
        {
            Q.pop_back();
        }
        Q.push_back(i);

        if(i>=m)
        {
            while(!Q.empty() && i-Q.front()>=m)
            {
                Q.pop_front();
            }
            cout<<a[Q.front()]<<" ";//单调递减序列。队头为最大值
        }
    }

    return 0;
}
