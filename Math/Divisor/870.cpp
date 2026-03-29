#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;

bool Prime(int x)
{
    if (x<2) return false;
    if (x==2) return true;
    if (x%2==0) return false;
    for(int i=3;i<=x/i;i+=2)
    {
        if (x%i==0) return false;
    }
    return true;
}

unordered_map<int,int> num;
void factors(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(!Prime(i)) continue;
        while (x%i==0)
        {
            num[i]++;
            x/=i;
        }
    }
    if (x>1) num[x]++;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        factors(a);
    }

    long long res=1; // 预防乘积过大
    for(auto it =num.begin();it!=num.end();it++)
    {
        res=res*(it->second+1) % M; // 每类因子可选可不选
    }

    cout<<res;

    return 0;
}