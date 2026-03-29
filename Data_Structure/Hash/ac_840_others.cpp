//#include <bits/stdc++.h>
//using namespace std;
//
//// 开放寻址法：开放寻址法是解决哈希表中冲突的一种方法。
//// 当通过哈希函数得到的索引位置已经被占用时，开放寻址法会按照一定的规则寻找下一个空闲位置。
//// 这种方法不需要额外的存储空间来存放冲突的元素，因此非常适合装载因子较小的哈希表。
//
//const int N=200003; // 开放寻址法，hash[]经验上开辟为题目要求的2~3倍
//const int null=0x3f3f3f3f; // 空值标志(一个大于1e9的数)
//int h[N];
//
//int find(int x)
//{
//    int k=(x%N+N)%N;
//    // 对于插入操作如果h[k]为空，返回k进行插入操作
//    // 对于查找操作如果h[k]为空，就说明x不在集合中
//    while(h[k]!=null && h[k]!=x)
//    {
//        k++;
//        if(k==N) k=0;
//    }
//    return k;
//}
//
//int main()
//{
//    memset(h,0x3f, sizeof(h));
//    int n;
//    cin>>n;
//
//    while(n--)
//    {
//        string op;
//        cin>>op;
//        int x;
//        cin>>x;
//        int k=find(x);
//        if(op=="I") h[k]=x;
//        else
//        {
//            if(h[k]!=null) cout<<"Yes"<<endl;
//            else cout<<"No"<<endl;
//        }
//    }
//    return 0;
//}