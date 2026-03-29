#include <bits/stdc++.h>
using namespace std;

// 注意题目表述：所有输入的字符串 总长度 不超过1e5
const int N=1e5+10;

int son[N][26],cnt[N],idx;
// 事实上son[i][j]存储的（即son[i][j]的值）是son[i][j]的子节点
// son[][]的每一行有公共的父节点


// idx为标记，表示当前结点的编号，cnt[idx]表示以编号为idx结点结尾的字符串个数
// 插入字符串的总长度不超过N，每个字符为a~z共26种可能

void insert(char *str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u = str[i]-'a'; // 将字符转化为数字，0~a,1~b,方便插入son[N][26]
        if(!son[p][u])    // 如果结点son[p][u]=0，即该结点不存在
        {
            son[p][u]=++idx; // 新建结点并编号,idx+1保证了son[][]每一行有的父节点相同
        }
        p=son[p][u]; // p指向其子节点
    }
    cnt[p]++; // 存在以该节点为尾的字符，count++
}

int query(char *str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u = str[i]-'a';
        if(!son[p][u]) return 0; // 节点不存在，即该字符串不存在，return 0
        p=son[p][u];             // 存在，找寻节点的子节点
    }
    return cnt[p];
}

char my_str[N];

int main()
{
     int n;
     cin>>n;
     while(n--)
     {
         char op;
         cin>>op>>my_str;
         if(op=='I')
         {
             insert(my_str);
         }
         else
         {
             cout<<query(my_str)<<endl;
         }
     }

    return 0;
}
