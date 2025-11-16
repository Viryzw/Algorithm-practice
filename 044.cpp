// Description: 有一个由'1'~'9'组成的字符串，现在需要将其分割成若干段，使每段字符串对应的数值小于等于k，需计算最少分割次数并返回，若无法成功分割则返回-1
// Input: 一个只有数字的字符串（最长10^5位）和一个数字k（最大10^9），空格隔开
// Output: 输出一个整数，表示完成解锁的最少操作步骤。如果无法完成解锁，则返回-1
// Sample 1
// Input: 165462 60      Output: 4
// Sample 2
// Input: 238182 5      Output: -1

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    long long k;
    cin >> s >> k;

    int splits = 1;
    long long cur = 0;

    for (char c: s) {
        int d = c - '0';

        if (d > k) {
            cout << -1 << endl;
            return 0;
        }

        long long newVal = cur * 10 + d;
        if (newVal < k) {
            cur = newVal;
        }
        else {
            splits++;
            cur = d;
        }
    }

    cout << splits << endl;
    return 0;
}