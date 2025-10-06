// Description: 给定能量的上界和下界，能量本身是回文数，且是一个回文数的平方
// Input: 输入两行，以回车分隔，分别表示 L 和 R；
// L：字符串，表示区间的上界（包含）；
// R：字符串，表示区间的下界（包含）；
// 1 <= len(L), len(R) <= 18
// Output: 一个整数，表示该区间内超共鸣体的数量
// Sample 1
// Input: 4 \\ 1000      Output: 4
// Sample 2
// Input: 1 \\ 2      Output: 1

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solution(string L, string R) {
    long long Lnum = stoll(L);
    long long Rnum = stoll(R);
    int count = 0;

    for (long long i = ceil(sqrt(Lnum)); i <= floor(sqrt(Rnum)); i++) {
        if (isPalindrome(to_string(i)) && isPalindrome(to_string(i * i))) {
            count++;
        }
    }
    return count;
}

int main()
{
    string L, R;
    cin >> L >> R;
    int count = solution(L, R);
    cout << count << endl;
    return 0;
}