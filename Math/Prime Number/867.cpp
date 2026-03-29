#include <bits/stdc++.h>
using namespace std;

bool Prime(int x)
{
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i<=x/i;i+=2)
    {
        if(x%i==0) return false;
    }
    return true;
}

void Prime_Factors(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(!Prime(i)) continue;
        int s=0;
        while(x%i==0)
        {
            x/=i;
            s++;
        }
        if(s>0) cout<<i<<" "<<s<<endl;
    }
    if(x>1) cout<<x<<" "<<1<<endl;
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        Prime_Factors(x);
    }
    return 0;
}