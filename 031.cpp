// Description: 输入一个整数a，按照从小到大的顺序，返回所有长度为a的180度旋转数
// 180度旋转数使一个数字从中心旋转180度之后，其数值保持不变的数字
// Input: 输入一个整数a，1<=a<=14
// Output: 输出一个由整数构成的数组，数字与数字之间用一个空格隔开
// Sample 1
// Input: 2      Output: 11 69 88 96
// Sample 2
// Input: 1      Output: 0 1 8

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<char, char>> pairs = {
    {'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}
};

void dfs(int left, int right, string &cur, vector<string> &res, int n) {
    if (left > right) {
        if (n == 1 || cur[0] != '0') {
            res.push_back(cur);
        }
        return;
    }

    for (auto &p: pairs) {
        cur[left] = p.first;
        cur[right] = p.second;
        if ((left == right) && (p.first != p.second)) {
            continue;
        }

        dfs(left + 1, right - 1, cur, res, n);
    }
}

int main()
{
    int a;
    cin >> a;
    vector<string> res;
    string cur(a, ' ');
    dfs(0, a-1, cur, res, a);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        if (i != res.size() - 1) {
            cout << res[i] << ' ';
        }
        else {
            cout << res[i] << endl;
        }
    }

    return 0;
}