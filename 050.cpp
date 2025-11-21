// Description: 宝石的价值由整数数组gemValues给出
// 每轮操作：数组被划分为左右两个非空区域，若两个分区价值不等则丢弃高价值分区，若价值相等则随机丢弃
// 未被丢弃分区总价值累加到得分中，且未被丢弃的分区组成新的行，进入下一轮
// 只剩一块宝石时游戏结束，计算最大得分
// Input: 一个整数数组gemValues，空格隔开
// Output: 一个整数，表示最大得分
// Sample 1
// Input: 6 2 3 4 5 5     Output: 18
// Sample 2
// Input: 7 7 7 7 7 7 7      Output: 28
// Sample 3
// Input: 4      Output: 0

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读取输入行
    string line;
    if (!getline(cin, line)) return 0;
    stringstream ss(line);
    vector<ll> a;
    ll v;
    while (ss >> v) a.push_back(v);

    int n = (int)a.size();
    if (n <= 1) {
        cout << 0 << "\n";
        return 0;
    }

    // prefix sums
    vector<ll> pre(n+1, 0);
    for (int i = 0; i < n; ++i) pre[i+1] = pre[i] + a[i];
    auto rangeSum = [&](int l, int r)->ll { return pre[r+1] - pre[l]; };

    // dp[l][r] for 0<=l<=r<n
    // use vector of vector ll, initialize 0 for length 1
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    // len = 2..n
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            ll best = 0;
            // try all cuts
            for (int k = l; k < r; ++k) {
                ll L = rangeSum(l, k);
                ll R = rangeSum(k+1, r);
                ll cand;
                if (L < R) {
                    cand = L + dp[l][k];
                } else if (L > R) {
                    cand = R + dp[k+1][r];
                } else { // equal
                    cand = L + max(dp[l][k], dp[k+1][r]);
                }
                if (cand > best) best = cand;
            }
            dp[l][r] = best;
        }
    }

    cout << dp[0][n-1] << "\n";
    return 0;
}
