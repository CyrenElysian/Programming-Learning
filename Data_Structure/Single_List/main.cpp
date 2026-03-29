#include <bits/stdc++.h>
using namespace std;

// 第 k 个插入的数并不是指当前链表的第k个数。
// 例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，
// 这n个数依次为：第1个插入的数，第2个插入的数，…第n个插入的数。

// 静态链表
const int N=1e5+10;
int v[N],p[N],idx=1;
// v[]为节点值,p[]为指针,p[0]作为头指针,节点不存值,只存储指向头节点的指针
// idx存储当前已经用到哪个结点,即第几个插入的数

// 表示在第k个插入的数后面插入一个数x
void insert(int k,int x)
{
    v[idx]=x;
    p[idx]=p[k];
    p[k]=idx;
    idx++;
    // 当 k=0 时 idx即位头节点
}

void del(int k)
// 表示删除第k个插入的数后面的数
// 当 k=0 时,头指针指向头节点的下一个节点,及删除现有的头节点
{
    p[k]=p[p[k]]; // p[k]=p[k+1]的问题: 第k个插入节点后面相邻的节点 不一定是第k+1个插入的节点
}

int main()
{
    int m;
    cin>>m;

    while(m--)
    {
        int k,x;
        char op;
        cin>>op;
        if(op == 'H')
        {
            cin>>x;
            insert(0,x);
        }
        else if (op == 'I')
        {
            cin>>k>>x;
            insert(k,x);
        }
        else
        {
            cin>>k;
            del(k);
        }
    }

    for(int i=p[0];i!=0;i=p[i])
    {
        cout<<v[i]<<' ';
    }
    return 0;
}
