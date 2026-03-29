#include <bits/stdc++.h>
using namespace std;

//“表达式求值”问题，两个核心关键点：
//（1）双栈，一个操作数栈，一个运算符栈；
//（2）运算符优先级，栈顶运算符，和，即将入栈的运算符的优先级比较：
//如果栈顶的运算符优先级低，新运算符直接入栈
//如果栈顶的运算符优先级高，先出栈计算，新运算符再入栈

stack<int> num;
stack<char> op;
unordered_map<char,int> my_hash{{'+',1},{'-',1},{'*',2},{'/',2}};

void figure()
{
    int a=num.top();
    num.pop();
    int b=num.top();
    num.pop();
    char symbol=op.top();
    op.pop();

    int res=0;
    // 注意运算顺序，先弹出的a是第二个操作数，b是第二个操作室
    if(symbol=='+') res=b+a;
    else if(symbol=='-') res=b-a;
    else if(symbol=='*') res=b*a;
    else if(symbol=='/') res=b/a;
    num.push(res);
}

int main()
{
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++) //isdigit 函数是 C++ 标准库中的一个函数，用于检查传递的 字符 是否为数字字符
    {
        if (isdigit(s[i])) // 如果是数字，读完整个数
        {
            int x=0;
            int j=i;
            while( j<s.size() && isdigit(s[j]) )
            {
                x=x*10+s[j]-'0';
                j++;
            }
            num.push(x);
            i=j-1; //s[j]为符号,但由于循环后i会加1,故让i在j的基础上减1,确保下次可以正确索引到符号
        }
        else if(s[i]=='(') // 遇到左括号直接入栈
        {
            op.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(op.top() != '(') // 当遇到右括号时，计算括号里
            {
                figure();
            }
            op.pop(); // 计算完后pop'('
        }
        else // 如果是运算符
        {
            while(op.size() && my_hash[op.top()] >= my_hash[s[i]])
            // 栈顶运算符优先级更高，先出栈计算，新运算符再入栈
            // 如果op.top()为'('，其哈希后值为0，小于加减(1)乘除(2)，故不执行figure，新运算符直接入栈
            {
                figure();
            }
            op.push(s[i]); // 如果新运算符优先级更高，则直接入栈
        }
    }
    while(op.size())
    {
        figure();
    }
    cout<<num.top()<<endl;
}