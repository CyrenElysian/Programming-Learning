#include <bits/stdc++.h>
using namespace std;

// 求n的二进制中第k位是几,从右向左分别为第0为,第1位……
// & 按位与; | 按位或; ~ 按位取反(与!不同); ^异或

int low_bit(int x)
{
    return x & -x;
    // 一个数的二进制补码与其相反数的二进制补码做 & 运算 可以得到x二进制补码右边的那个 1以及其右边所有的 0
}

int main()
{

    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        int count=0;
        while(x>0)
        {
            x-= low_bit(x);
            count++;
        }
        cout<<count<<" ";
    }
    return 0;
}
