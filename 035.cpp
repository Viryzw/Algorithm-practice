// Description: 现在有一个链表，现在需要反转，并将反转后链表每个节点的val按顺序存在数组中
// Input: 输入一个链表
// Output: 输出一个整数数组
// Sample 1
// Input: 3->6->4->1      Output: 1 4 6 3
// Sample 2
// Input: 0      Output: 0
// Sample 2
// Input: 空      Output: 空

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    if (s.empty()) {
        return 0;
    }

    vector<char> list;
    for(int i = 0; i < s.length(); i++) {
        if (s[i] != '[' && s[i] != ']' && s[i] != ' ') {
            list.push_back(s[i]);
        }
    }

    reverse(list.begin(), list.end());
    for (int i = 0; i < list.size(); i++) {
        if (i == list.size() - 1) {
            cout << list[i] << endl;
        }
        else{
            cout << list[i] << ' ';
        }
        
    }

    return 0;
}
