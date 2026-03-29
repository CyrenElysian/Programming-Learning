#include <bits/stdc++.h>
using namespace std;

vector<int> Multi(vector<int> A,int b)
{
    int t=0;
    vector<int> C;
    for(int i=0;i<A.size();i++)
    {
        if(i<A.size())
        {
            t+=A[i]*b;
            C.push_back(t%10); // (被乘数[i]*乘数+进位)%10=本位
            t/=10;             // (被乘数[i]*乘数+进位)/10=进位
        }
    }

    if(t!=0) // 最高位进位
    {
        C.push_back(t);
    }

    while(C.back()==0 && C.size()>1) // 弹出高位的0
    {
        C.pop_back();
    }
    return C;
}

int main()
{
    string a; // 数字较大，转成字符串类型，范围[0,size-1]
    int b;
    vector<int> A;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    auto C = Multi(A,b);

    for(int i=C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }

    return 0;
}
