#include <bits/stdc++.h>
using namespace std;

// 15=5*3
void Prime(int x)
{
    if (x<2)
    {
        cout<<"No"<<endl;
        return;
    }
    if (x==2)
    {
        cout<<"Yes"<<endl;
        return;
    }
    if (x%2==0)
    {
        cout<<"No"<<endl;
        return;
    }
    for(int i=3;i<=x/i;i=i+2) // 不要用开方，效率低；也不要用i*i
    {
        if (x%i==0)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int a;
        cin>>a;
        Prime(a);
    }

    return 0;
}
