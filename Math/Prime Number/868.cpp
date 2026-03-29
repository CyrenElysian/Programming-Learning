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

int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=2;i<=n;i++)
    {
        if (Prime(i)) count++;
    }
    cout<<count<<endl;
    return 0;
}