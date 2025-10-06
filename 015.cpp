// Description: 字符串生成，变成原来长度的两倍，并且新的一半是反转
// 你的任务是找出原始字符串的最小可能长度
// Input: 最终生成的字符串s
// Output: 一个整数，表示原始字符串的最小可能长度
// Sample 1
// Input: ABBAABBA      Output: 2
// Sample 2
// Input: AA      Output: 1
// Sample 3
// Input: ABCABC     Output: 6

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int solution(string s) {
    long long len = s.size();
    if (len % 2 != 0) {
        return len;
    }

    long long half = len / 2;
    string a = s.substr(0, half);
    string b = s.substr(half);
    reverse(a.begin(), a.end());
    
    if (a == b) {
        return solution(a);
    }
    else {
        return len;
    }
}

int main() {
    string s;
    cin >> s;
    cout << solution(s) << endl;
    return 0;
}