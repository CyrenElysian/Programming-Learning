#include <bits/stdc++.h>
using namespace std;

const int N=10;
int path[N]; // 用于保存序列
int state[N]; // 用于记录数字是否使用

int n; // 序列长度
void dfs(int length) // length 为序列当前长度
{
    if(length > n) // length大于给定总长度，输出序列 （不能将大于改为等于，因为cout语句在赋值语句(path[]=i)上面，此时输出的序列不完整）
    {
        for(int i=1;i<=n;i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++)
    {
        if(state[i]==0)
        {
            path[length]=i;
            state[i]=1;
            dfs(length+1); // 填写下一位
            state[i]=0; // 取回数字，进行下一轮循环（底层进行下一轮循环试探数字，若底层循环完，退至倒数第二层，依次类推）
        }
    }
}

int main()
{

    cin>>n;
    dfs(1);
    return 0;
}
