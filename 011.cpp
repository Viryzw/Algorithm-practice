// Description: 有一段长度为正整数的木头，将以下操作持续到木头长变为2或更小
// 选择两个位置将木头截成长度为正整数三段，丢弃最长和最短
// 当长度为n的木头进行此操作，令f(n)为该操作可进行的最多次数
// 给出x，输出使f(n)=x的最大整数n
// Input: 输入最大次数
// Output: 输出最大长度
// Sample 1
// Input: 1      Output: 6
// Sample 2
// Input: 2      Output: 14

#include<iostream>
#include<vector>

using namespace std;

// a_n+1 = 2a_n + 2

int main()
{
    long long x;
    cin >> x;
    long long ans = 2;
    for (long long i = 0; i < x; i++) {
        ans += 1 + (ans + 1);
    }
    cout << ans << endl;
    return 0;
}