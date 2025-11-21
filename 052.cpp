// Description: 初始下载速度为每个工具1分钟，每分钟可执行两种操作
// 利用当前网速下载；用一分钟使下载速度变成两倍
// 计算至少下载完n个工具，最少需要多久
// Input: 一个正整数n表示要下载的工具数量，1<=n<=10^5
// Output: 下载完工具需要的分钟数
// Sample 1
// Input: 2     Output: 2
// Sample 2
// Input: 4     Output: 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = LLONG_MAX;

    // 枚举加速次数 t（不可能超过 17~20）
    for (int t = 0; t <= 20; t++) {
        long long speed = 1LL << t;  // 2^t
        long long time_download = (n + speed - 1) / speed;  // ceil(n / speed)
        long long total = t + time_download;
        ans = min(ans, total);
    }

    cout << ans << endl;
    return 0;
}
