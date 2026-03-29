#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int num[N];
// r为右边界,l为左边界
int s[N]; // 用于统计num[]在编号[l,r]范围内的数的个数

int main() {
    int n;
    cin>>n;
    for(int r=1;r<=n;r++)
    {
        cin>>num[r];
    }
    int res=0;

    for(int r=1,l=1;r<=n;r++)
    {
        s[num[r]]++; // 右指针移动,对应数的个数加1
        while(s[num[r]]>1) // 个数大于2,左指针移动,左指针原来指的数减1,直到num[r]的数量为1
        {
            s[num[l]]--;
            l++;
        }
        res=max(res,r-l+1);
    }
    cout<<res<<endl;
    return 0;
}
