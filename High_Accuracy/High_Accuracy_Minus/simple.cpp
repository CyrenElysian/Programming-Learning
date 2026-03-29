#include <bits/stdc++.h>
using namespace std;

// 一种更容易理解的做法

bool cmp(vector<int> &a, vector<int> &b)
{
    if(a.size()!=b.size()) return a.size()>b.size();

    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]!=b[i]) return a[i]>b[i];
    }

    return true;
}

vector<int> sup(vector<int> &a,vector<int> &b) // a>b
{
    vector<int> c;
    int t=0; // 借位
    for(int i=0;i<b.size();i++)
    {
        int diff=a[i]-b[i]-t;
        if(diff<0)
        {
            diff+=10;
            t=1;
        }
        else t=0;
        c.push_back(diff);
    }
    for(int i=b.size();i<a.size();i++)
    {
        int diff=a[i]-t;
        if(diff<0)
        {
            diff+=10;
            t=1;
        }
        else t=0;
        c.push_back(diff);
    }
    while(c.size()>1 && c.back()==0) c.pop_back();
    return c;
}

int main()
{
    string s1, s2;
    vector<int> a, b;
    cin >> s1 >> s2;
    for (int i = s1.size() - 1; i >= 0; i -- ) a.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i -- ) b.push_back(s2[i] - '0');

    vector<int> c;

    if (cmp(a, b)) c = sup(a, b);
    else c = sup(b, a), cout << '-';

    for (int i = c.size() - 1; i >= 0; i -- ) cout << c[i];
    cout << endl;

    return 0;
}
