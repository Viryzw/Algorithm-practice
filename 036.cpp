// Description: 找出一个字符串中的最长对称子串
// Input: 输入一个字符串（长度大于等于1）
// Output: 输出一个字符串
// Sample 1
// Input: cabak      Output: aba
// Sample 2
// Input: fggd      Output: gg
// Sample 3
// Input: a      Output: a

#include<iostream>
#include<string>

using namespace std;

string solution(const string &s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

int main()
{
    string s;
    cin >> s;
    string ans = "";

    for(int i = 0; i < s.size(); i++) {
        string odd = solution(s, i, i);
        string even = solution(s, i, i + 1);

        string longer = (odd.size() >= even.size()) ? odd : even;

        if (longer.size() >= ans.size()) {
            ans = longer;
        }
    }

    cout << ans << endl;
    return 0;
}