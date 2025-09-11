// Input: 输入一个仅包含英文字母和空格的字符串 str1 <= str.length <= 10000
// Output: 输出最后那个单词的长度
// Sample 1
// Input: aa bb ccc     Output: 3
// Sample 2
// Input: abccc     Output: 5


#include<iostream>
using namespace std;

int solution(string s){
    int count = 0;
    int size = s.size() - 1;

    while (size >= 0 && s[size] == ' ') {
        size--;
    }

    while (size >= 0 && s[size] != ' ') {
        count++;
        size--;
    }

    return count;
}

int main()
{
    string str;
    getline(cin, str);
    cout << solution(str) << endl;
    return 0;
}