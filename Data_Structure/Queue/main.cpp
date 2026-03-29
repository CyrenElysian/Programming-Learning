#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int my_stack[N];
int head=1,tail=1;

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            my_stack[tail++] = x;
        }
        else if (op == "pop")
        {
            head++;
        }
        else if (op == "empty") 
        {
            cout << (tail==head ? "YES" : "NO") << endl;
        }
        else
        {
            cout << my_stack[head] << endl;
        }
    }
}