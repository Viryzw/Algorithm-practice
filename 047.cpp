// Description: 输入一个整数数组，在其中挑选元素计算出最大乘积
// Input: 一个整数数组，空格隔开
// Output: 一个整数，表示将能量值归零所需的最少操作次数
// Sample 1
// Input: 3 -1 -5 2 5 -9      Output: 1350
// Sample 2
// Input: -4 -5 -4      Output: 20


#include<bits/stdc++.h>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<long long> nums;
    int x;
    while (ss >> x) nums.push_back(x);

    if (nums.empty()) return 0;

    if (nums.size() == 1) {
        cout << nums[0] << endl;
        return 0;
    }

    vector<long long> neg, pos;
    int zeroCnt = 0;
    for (auto v : nums) {
        if (v > 0) pos.push_back(v);
        else if (v < 0) neg.push_back(v);
        else zeroCnt++;
    }

    // 若负数个数为奇数，删除绝对值最小的
    if (neg.size() % 2 == 1) {
        auto it = min_element(neg.begin(), neg.end(),
            [](long long a, long long b) { return llabs(a) < llabs(b); });
        neg.erase(it);
    }

    // 若全是 0
    if (pos.empty() && neg.empty() && zeroCnt != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long product = 1;
    for (auto v : pos) product *= v;
    for (auto v : neg) product *= v;

    cout << product << endl;
    return 0;
}
