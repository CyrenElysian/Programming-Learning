#include <bits/stdc++.h>
using namespace std;

// 较复杂的处理,不建议
vector<int> Minus(vector<int> A,vector<int>B)
{
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++)
    {

        if(i+1<=B.size()) // 考虑A与B的位数
        {
            if(t==0)
            {
                int temp=A[i]-B[i];
                if(temp<0)
                {
                    temp+=10;
                    C.push_back(temp);
                    t=1;
                }
                else
                {
                    C.push_back(temp);
                }
            }
            else
            {
                int temp=A[i]-1-B[i];
                if(temp<0)
                {
                    temp+=10;
                    C.push_back(temp);
                }
                else
                {
                    C.push_back(temp);
                    t=0;
                }
            }
        }

        else
        {
            // 考虑连续借位 eg:100-1
            if(t==1 && A[i]>0)
            {
                C.push_back(A[i]-1);
                t=0;
                continue;
            }
            else if(t==1 && A[i]==0)
            {
                C.push_back(9);
                continue;
            }
            C.push_back(A[i]);
        }
    }
    while(C.back()==0 && C.size()>1)
    {
        C.pop_back();
    }
    return C;
}