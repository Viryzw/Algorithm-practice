// 小明想要在王者荣耀游戏里晋升一个段位，假设他一共需打了n场比赛，且必须成功赢得至少70%的场次才能成功晋升。
// 假设每场比赛小明获胜的概率分别为p1，p2，…，pn，请帮他算出成功晋级段位的概率是多少？
// 输入：参数1：整数num（0 <= num <= 1000），表示比赛的场数。
// 参数2：整数数组p[num] = {p1，p2，…，pnum}，其中pi表示小明有pi%的概率赢得第i场比赛。（0 <= pi <= 100）
// 输出：成功晋级段位的概率，保留小数点后5位，最后结果四舍五入。

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double calculatePassProbability(vector<double>& p, int num) {
    vector<double> dp(num + 1, 0.0);
    dp[0] = 1.0;  // 没打比赛时，赢0场的概率是1

    // 动态规划
    for (int i = 0; i < num; i++) {
        // 必须从后往前更新，否则会覆盖还没用到的dp[j-1]
        for (int j = i + 1; j >= 0; j--) {
            double win = p[i];
            double lose = 1 - p[i];
            if (j > 0)
                dp[j] = dp[j] * lose + dp[j - 1] * win;
            else
                dp[j] = dp[j] * lose;
        }
    }

    // 至少赢70%
    int need = ceil(0.7 * num);
    double ans = 0.0;
    for (int j = need; j <= num; j++)
        ans += dp[j];

    return ans;
}

int main() {
    int num;
    cin >> num;

    vector<double> p(num);
    for (int i = 0; i < num; ++i) {
        cin >> p[i];
        p[i] /= 100;  // 转换为[0,1]区间
    }

    double ans = calculatePassProbability(p, num);

    cout << fixed << setprecision(5) << ans + 1e-9 << endl;  // 保留5位小数
    return 0;
}
