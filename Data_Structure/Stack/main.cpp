#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int my_stack[N];
int top=0;

int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        string op;
        cin>>op;
        if(op=="push")
        {
            int x;
            cin>>x;
            my_stack[++top]=x;
        }
        else if(op=="pop")
        {
            top--;
        }
        else if(op=="empty")
        {
            cout<<(top?"NO":"YES")<<endl;
        }
        else
        {
            cout<<my_stack[top]<<endl;
        }
    }

    return 0;
}
