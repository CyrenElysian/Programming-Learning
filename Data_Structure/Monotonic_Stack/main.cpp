#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int my_stack[N];
int top=0;

// 每输入一个数，判断它与栈顶元素的大小关系。如果比栈顶元素大，输出栈顶元素，该元素入栈；如果比栈顶元素小，弹出栈顶元素，与比较新栈顶元素比较，重复此过程

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(top && my_stack[top]>=x)
        {
            top--;
        }
        if(top)
        {
            cout<<my_stack[top]<<" ";
        }
        else
        {
            cout<<-1<<" ";
        }
        my_stack[++top]=x;
    }
    return 0;
}
