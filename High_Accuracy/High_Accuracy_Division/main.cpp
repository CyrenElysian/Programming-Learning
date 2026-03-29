#include <bits/stdc++.h>
using namespace std;

vector<int> Division(vector<int> A,int b,int &r) // C为商 余数为r
{
    vector<int> C;
    r=0;
    for(int i=A.size()-1;i>=0;i--) // 从首位开始做除法
    {
        r=r*10+A[i];
        C.push_back(r/b);
        r %=b;
    }
    reverse(C.begin(),C.end());
    while(C.back()==0 && C.size()>1)
    {
        C.pop_back();
    }
    return C;
}

int main()
{
    string a; // 数字较大，转成字符串类型，范围[0,size-1]
    int b,r;
    vector<int> A;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }

    auto C = Division(A,b,r);

    for(int i=C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
    cout<<endl;
    cout<<r;
    return 0;
}
