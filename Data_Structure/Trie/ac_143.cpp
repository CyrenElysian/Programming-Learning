#include <bits/stdc++.h>
using namespace std;

// 为使异或值最大，应使二进制各位置数对应不相等，且高位不同异或得到的值更大

const int N=1e5+10;
const int M=3e6+1e5+10; // 最多1e5个数，每个数的二进制不超过31位(30位到0位) 1e5*31=3e6+1e5

int son[M][2],idx;


void insert(int x)
{
    int p=0;
    for(int i=30;i>=0;i--) // 从高到低处理，因为高位比较重要
    {
        int &s=son[p][x>>i & 1]; // x右移i位 再与1做与运算，即得到关心位置的二进制
        //int &s是对son[p][x>>i & 1]取了别名，修改s即修改son[p][x>>i & 1]
        if(!s) s=++idx; // 节点为空，新建节点
        p=s;
    }
}

int search(int x)
{
    int p=0;
    int res=0;
    for(int i=30;i>=0;i--)
    {
        int s=x>>i & 1;
        if(son[p][!s]) // 如果存在第i位二进制的取反
        {
            res+=1<<i; // res自加1<<i
            p=son[p][!s]; // p指向son[p][!s]的子节点
        }
        else // 如果不存在第i位二进制的取反，res值不变，p指向son[p][s]的子节点
        {
            p=son[p][s];
        }
    }
    return res;
}

int num[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        insert(num[i]);
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=max(res, search(num[i]));
    }
    cout<<res;
}



