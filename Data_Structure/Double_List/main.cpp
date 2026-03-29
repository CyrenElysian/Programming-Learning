#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int v[N],l[N],r[N],idx;


// 由于idx从2计数,故函数输入的k'与题目要求的k关系为:k'=k+1,这点对于del()同理

void insert(int k,int x)
{
    v[idx]=x;
    l[idx]=k;
    r[idx]=r[k]; // 第k插入节点右边可能并非第k+1插入节点

    l[r[k]]=idx; // 这两句顺序不能颠倒
    r[k]=idx;
    
    idx++;
}
// 当插入左端点时,k=0;当插入右端点时,k=l[1]

void del(int k)
{
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}


int main()
{
    r[0]=1; // 因在链表左、右端插入节点的需要,需空置两个节点作为左右端点,编号为0,1,故idx从2开始
    l[1]=0;
    idx=2;
    int m;
    cin>>m;

    while(m--)
    {
        string op;
        cin>>op;
        int k,x;
        if (op == "L")
        {
            cin >> x;
            insert(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if (op == "D") // 表示将第k个插入的数删除
        {
            cin >> k;
            del(k + 1);
        }
        else if (op == "IL") // 表示在第k个插入的数左侧插入一个数
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else // // 表示在第k个插入的数右侧插入一个数
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    for(int i=r[0];i!=1;i=r[i])
    {
        cout<<v[i]<<' ';
    }

    return 0;
}
