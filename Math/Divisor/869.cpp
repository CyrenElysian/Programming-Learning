#include <bits/stdc++.h>
using namespace std;

void factors(int x)
{
    stack<int> s;
    for(int i=1;i<=x/i;i++)
    {
        if(x%i==0)
        {
            if (x/i!=i) s.push(x/i);
            cout<<i<<" ";
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}



int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        factors(x);
    }

    return 0;
}
