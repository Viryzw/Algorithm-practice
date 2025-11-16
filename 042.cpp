// Description: 给定一个工作时长序列，不能挑选连续两次安排，计算他最大工作时长
// Input: 输入多个整数，以空格隔开，表示过去一段时间内每日的盈利情况
// Output: 输出一个整数，表示最大收益值
// Sample 1
// Input: 2 7 9 3 1      Output: 12
// Sample 2
// Input: 2 1 4 5 3 1 1 3      Output: 12

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int x;

    while (ss >> x) nums.push_back(x);

    if (nums.empty()) {
        cout << 0 << endl;
        return 0;
    }
    if (nums.size() == 1) {
        cout << nums[0] << endl;
        return 0;
    }

    // dp[i-2], dp[i-1]
    int prev2 = nums[0];                  // dp[0]
    int prev1 = max(nums[0], nums[1]);    // dp[1]

    for (int i = 2; i < nums.size(); i++) {
        int cur = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = cur;
    }

    cout << prev1 << endl;
    return 0;
}
