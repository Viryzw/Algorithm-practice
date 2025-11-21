// Description: 9种零件，cost[i]表示第i+1种零件的成本；总成本等于target，使编号最大，零件可以重复使用
// Input: 一个整数数组cost，长度为9，表示每种零件的制造成本 1 <= cost[i] <= 5000
// 一个整数 target，表示总成本的目标值 1 <= target <= 5000
// Output: 一个字符串，表示最大装配编号，若无法满足条件返回 "0"
// Sample 1
// Input: 4 3 2 5 6 7 2 5 5 \\ 9      Output: 7772
// Sample 2
// Input: 7 6 5 5 5 6 8 7 8 \\ 12      Output: 85
// Sample 3
// Input：2 4 6 2 4 6 4 4 4 \\ 5        Output: 0

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cost(9);
    for (int i = 0; i < 9; i++) cin >> cost[i];
    int target;
    cin >> target;

    // dp[t] = 最大位数，初始化为 -inf
    vector<int> dp(target + 1, -1e9);
    dp[0] = 0;

    // DP 计算最大位数
    for (int t = 1; t <= target; t++) {
        for (int i = 0; i < 9; i++) {
            if (t >= cost[i])
                dp[t] = max(dp[t], dp[t - cost[i]] + 1);
        }
    }

    // 无法组成
    if (dp[target] < 0) {
        cout << "0";
        return 0;
    }

    // 构造答案：从 9→1
    string ans = "";
    int t = target;

    for (int d = 8; d >= 0; d--) {
        while (t >= cost[d] && dp[t] == dp[t - cost[d]] + 1) {
            ans.push_back('1' + d);
            t -= cost[d];
        }
    }

    cout << ans;
    return 0;
}
