//#include <bits/stdc++.h>
//using namespace std;
//
//// 拉链法：将每个数经过hash函数映射后，结果相同的用一个链表连接起来
//
//const int N=100003; // 先找一个大于哈希表大小上限的质数，通常选择一个质数作为表长，这样可以有效减少哈希冲突的发生
//int h[N],e[N],ne[N],idx;
//// h[i]存储的是第i链表的第一个节点的索引，main()函数中将其初始-1
//
//void insert(int x)
//{
//    int k=(x%N+N)%N; // 防止x为负值或比N大的负值，导致哈希值为负数的情况
//    e[idx]=x;
//    ne[idx]=h[k]; // 头插法，新结点指向链表头结点，第一个插入的结点ne[]值为-1，由于是头插，所以链表最后一个节点的ne[]为-1，可作为终止条件
//    h[k]=idx;   // 链表头结点变为idx
//    idx++;
//}
//
//bool search(int x)
//{
//    int k=(x%N+N)%N;
//    for(int i=h[k];i!=-1;i=ne[i]) // i=-1为终止条件
//    {
//        if(e[i]!=x) continue;
//        return true;
//    }
//    return false;
//}
//
//int main()
//{
//    // void *memset(void *str, int c, size_t n)
//    // memset() 函数将指定的值 c 复制到 str 所指向的内存区域的前 n 个字节
//    memset(h,-1,sizeof(h)); // 将数组h的每一个字节都设置为-1的二进制形式（1111 1111）
//    // 对于一个 int类型（通常占4个字节）的变量来说，当它的每一个字节都被设置为 1111 1111时，整个 int变量的值恰好就是 -1
//    int n;
//    cin>>n;
//    while(n--)
//    {
//        string op;
//        cin>>op;
//        int x;
//        cin>>x;
//        if(op=="I") insert(x);
//        else
//        {
//            if(search(x)==1)
//            {
//                cout<<"Yes"<<endl;
//            }
//            else
//            {
//                cout<<"No"<<endl;
//            }
//        }
//
//    }
//
//    return 0;
//}
