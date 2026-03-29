#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> A,vector<int> B)
{
    if(A.size() != B.size())
    {
        return A.size() > B.size();
    }
    for(int i=A.size()-1;i>=0;i--)
    {
        if(A[i] != B[i])
        {
            return A[i] > B[i];
        }
    }
    return true;
}

vector<int> Minus(vector<int> A,vector<int>B)
{
    vector<int> C;

    // 这里用单独的变量t来计算每一位的结果,相比直接使用A[i]-B[i]更方便,可对比 complex.cpp

    for(int i=0,t=0;i<A.size();i++)
    {
        // t为错位标志,t=0表示无借位,t=1表示有借位
        t=A[i]-t; // 如果有借位,A[i]-1赋值给t

        // 这一步很关键
        if(i+1<=B.size()) // 在默认A>B的条件下,如果作差位数在B的范围内才作差,否则执行A[i]-t(t=0)
        {
            t-=B[i];
        }

        C.push_back((t+10)%10); // 无论t<0还是t>=0,都可以得到这一位的正确结果

        if(t<0) // 如果t<0,代表第i位需借位,置t=1,做下一位减法前先执行 t=A[i]-t
        {
            t=1;
        }
        else // t>0,代表无需借位,置t=0
        {
            t=0;
        }
    }

    while(C.back()==0 && C.size()>1) // 处理高位为0的情况,并且保证两数相等时至少输出0
    {
        C.pop_back();
    }

    return C;
}

// 对于A-B,若A<B,计算B-A,添加负号
int main()
{
    string a, b; // 数字较大，转成字符串类型，范围[0,size-1]
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }

    if(cmp(A,B))
    {
        auto C = Minus(A, B);
        for(int i=C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }
    else
    {
        auto C = Minus(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }

    return 0;
}
