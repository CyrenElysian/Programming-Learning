#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;

// 对于两个较大的整数相加(基本数据类型无法容纳超长位数的大数),将两个数当成字符串存进两个动态数组A,B中
// 数的低位先存(如123存储为321),这是因为最高位相加后还可能会进位,所有高位往后存
// 同时遍历两个动态数组A,B,同位置相加,将结果模10运算后再push到C中,如果有进位则带入下一次计算中
// 最后逆序遍历C

vector<int> add(vector<int> A, vector<int> B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
        {
            t += A[i];
        }
        if (i < B.size())
        {
            t += B[i]; // 两数组同位相加
        }
        C.push_back(t % 10); // 模10运算后
        t /= 10; // 若和大于等于10,t=1,1会带入下一次求和计算;若小于10,t=0;
    }
    if (t)
    {
        C.push_back(1); // 如果最高位求和大于等于10,进位
    }
    return C;
}

int main() {
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
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    return 0;
}
