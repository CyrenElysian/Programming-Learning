// 注：子序列可以不连续

#include <bits/stdc++.h>
using namespace std;

int length_of_LIS(vector<int>& nums)
{
    int n=nums.size();
    if (n==0) return 0;

    // dp[i]表示以第i个元素为结尾的最长上升子序列的长度，初始化为1
    vector<int> dp(n,1);
    for(int i=1;i<n;i++) // vector数组从0开始，显然dp[0]=1，略过
    {
        for(int j=0;j<=i-1;j++)
        {
            if(nums[j]<nums[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    // max_element用于在指定范围内查找最大元素的迭代器，左闭右开
    return *max_element(dp.begin(),dp.end());
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<=n;i++)
    {
        cin>>nums[i];
    }
    cout<<length_of_LIS(nums)<<endl;
    return 0;
}