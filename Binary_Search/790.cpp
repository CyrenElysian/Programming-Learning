#include <bits/stdc++.h>
using namespace std;

double solve(double x)
{
    double l=-1e4,r=1e4;
    while(r-l>1e-7) // 不用while(l<r)，涉及到精度问题，具体情况具体分析
    {
        double mid=(l+r)/2;
        if(mid*mid*mid<=x)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}

int main()
{
    double n;
    cin>>n;
    printf("%.6lf", solve(n));
    return 0;
}