// 原算法对于数组每个位置的值都要重新遍历一遍数组O(n^2)，显然存在可以优化的空间
// 现在我们维护一个数组dp[]，dp[i]表示长度为i的上升子序列的末尾元素的最小可能值
// 算法流程：顺序遍历所有元素，
// (1)如果当前元素比当前上升子序列的末尾元素还大，就将其添加到子序列的末尾，序列长度加1
// (2)否则，二分查找当前上升子序列中第一个 大于等于 当前元素的值，将该位置上的元素替换为当前元素
// 其中(1)很好理解，对于(2)替换操作的含义是，
// 当上升子序列不再递增时，若以当前遍历到的元素为末尾元素，所得到的最大上升子序列

// 举个例子，对于序列[1,3,4,2]
// i=1,num[i]=1,         dp[1]=1;       ,length=1
// i=2,num[i]=3>dp[1]=1  dp[2]=3;       ,length=2
// i=3,num[i]=4>dp[2]=3, dp[3]=4;       ,length=3
// i=4,num[i]=2<dp[3]=4, dp[2]=2(3->2)  ,length=3
// 在第4步，遍历到的元素2比上升子序列末尾元素4小，将上升子序列中第一个大于等于2的元素替换为2
// 其dp[]数组下标为2，表示长度为2的上升子序列末尾元素的最小值为2

// 如果序列为[1,3,4,2,3,4,5]
// i=5,num[i]=3<dp[3]=4, dp[3]=3(4->3)  ,length=3
// i=6,num[i]=4>dp[3]=3, dp[4]=4        ,length=4
// i=7,num[i]=5 ...
// 可以发现，此算法在过程可以动态维护长度为i的上升子序列的最小末尾值
// 可以推出，当遍历完数组后，dp[]数组长度(从1开始计数)即是最长上升子序列长度
#include <bits/stdc++.h>
using namespace std;

// STL:lower_bound() 返回第一个 大于等于 指定值的元素的迭代器
//     upper_bound() 返回第一个   大于   指定值的迭代器
// 如果找不到，它会返回end()迭代器的位置


int length_of_LIS(vector<int>& nums)
{
    int n=nums.size();
    if(n==0) return 0;

    vector<int> dp;
    for(int i=0;i<n;i++)
    {
        int pos= lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
        if(pos==dp.size()) 
        {
            dp.push_back(nums[i]);
        }
        else
        {
            dp[pos]=nums[i];
        }
    }

    return dp.size();
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cout<<length_of_LIS(nums)<<endl;
    return 0;
}