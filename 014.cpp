// Description: 在一个神秘的实验室里，科学家们开发了一种特殊的字符串生成算法。他们从一个初始字符串s开始，并按照如下规则生成无限长的神秘字符串：
// 1、定义F(s)为s后接上s向右循环移动一个字符后的结果。例如，F("ABC") = "ABCCAB"（因为 "ABC" 右移 1 位后变成 "CAB"）。
// 2、他们重复应用F(s)，每次操作后字符串长度翻倍。
// 给定初始字符串S和一个索引N，找到无限生成的神秘字符串中第N个字符，索引从1开始
// Input: 输入包含一行，由一个字符串s和一个整数N组成，其中：
// s仅由大写英文字母组成，长度最多为30。
// 1 <= N <= 10^18
// Output: 输出第N个字符
// Sample 1
// Input: AB 3      Output: B
// Sample 2
// Input: ABC 8     Output: A


#include<iostream>
#include<string>

using namespace std;

char solution(string s, long long N) {
    long long index = N - 1;
    long long len = s.size();

    while (len < N) {
        len *= 2;
    }

    while (len > s.size()) {
        long long half = len / 2;
        if (index < half) {}
        else if (index == half) {
            index -= 1;
        }
        else {
            index -= half + 1;
        }
        
        len /= 2;
    }

    return s[index];
}

int main() {
    string s;
    long long N;
    cin >> s >> N;
    cout << solution(s, N) << endl;
    return 0;
}