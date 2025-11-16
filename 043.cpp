// Description: 挑选一些果树，按照果子数量nums[i]从小到大排序，挑选的果树数量至少为2，从第二棵果树开始，其果实数量必须等于前一棵果树果实数量的平方
// 计算满足条件的最大果树数量并返回，不存在则返回-1
// Input: 输入多个整数，以空格隔开，表示果树的果实数量，未排序
// Output: 输出一个整数，表示满足条件的最多果树数量
// Sample 1
// Input: 4 3 6 16 8 2      Output: 3
// Sample 2
// Input: 2 3 5 6 7      Output: -1

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<long long> nums;
    long long x;
    while (ss >> x) nums.push_back(x);

    if (nums.empty()) {
        cout << -1 << endl;
        return 0;
    }

    sort(nums.begin(), nums.end());

    unordered_set<long long> st(nums.begin(), nums.end());

    int maxLen = 1;

    for (long long start : nums) {
        int len = 1;
        long long cur = start;

        while (true) {
            if (cur > 1e9) break; // 防止溢出
            long long nxt = cur * cur;
            if (st.count(nxt)) {
                len++;
                cur = nxt;
            } else {
                break;
            }
        }

        maxLen = max(maxLen, len);
    }

    cout << (maxLen >= 2 ? maxLen : -1) << endl;
    return 0;
}
