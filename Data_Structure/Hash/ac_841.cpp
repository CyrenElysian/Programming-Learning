#include <bits/stdc++.h>
using namespace std;
// 字符串前缀哈希法，把字符串看成一个P进制数字（将其映射为十进制再模Q得到其哈希值），实现不同的字符串映射到不同的数字
// 经验：进制P选择131或13331，Q选择2^64，一般情况不会出现哈希值冲突的情况

// h[i]: 前i个字符组成的 (131进制) 的哈希值(下标从 1 开始)
// p[i]: 131进制第i位(从右至左分别为第0位，第1位……)对应的十进制数
// 核心思想：把整个字符串看成一个 131 进制的无符号 64 位整数(unsigned long long)
// 注：这里选择unsigned long long 是因为其为64位二进制，当计算h[i]的值时若其发生进位，h[i]只保留0到63位，等价于进行了mod Q(2^64)

typedef unsigned long long ULL;
const int N=1e5+10;
const int P=131;

ULL h[N],p[N];
char str[N];
// h[i]: 前i个字符组成的 (131进制) 的哈希值(下标从 1 开始)
// p[i]: 131进制第i位(从右至左分别为第0位，第1位……)对应的十进制数，即131^i，用于左移操作

// 利用前缀哈希 h[l] 和 h[r] 计算 字符串str[l,r]的哈希值
// str[l,r]在str[1,r]的低位上，且str[1,l-1]的哈希值h[l-1]已知
// 故可以将str[1,l-1]左移至最高位与str[1,r]对齐(即逻辑上 在str[1,l-1]后面补 r-l+1 个0，使其长度变为r)，
// 得到一个对应的值，再用h[r]减去这个值就是str[l,r]的哈希值

ULL Get_Hash(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1]; // 在后面补 (r-l+1) 个0，相当于乘进制 P 的 r-l+1次方
    // 用 h[l-1]*P^(r-l+1) 把前缀 [1,l-1] 的哈希值左移到与 [1,r] 对齐，再相减即得子串 [l,r] 的哈希
}

int main()
{
    int n,m;
    cin>>n>>m>>(str+1);
    h[0]=0; // 初始值为0
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+str[i]; // 转成十进制
        // str[i] 是 char，但 char 在运算时会先整型提升成 int(ascii码中对应值), 再被转换成 unsigned long long
    }
    while(m--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(Get_Hash(l1,r1)== Get_Hash(l2,r2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}

