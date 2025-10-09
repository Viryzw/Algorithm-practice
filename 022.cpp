// Description: 给出多项式px^3+qx*2+rx+s=0，并约定该方程存在三个不同实根（-100，100）要求由小到大输出三个根，保留两位，空格间隔
// Input：一行，包含四个实数pqrs
// Output：一行，包含三个实数解，从小到大排列，精确到小数点后两位
// Sample 1
// Input: 1 -5 -4 20     Output: -2.00 2.00 5.00
// Sample 2
// Input: -1 6 -11 6      Output: 1.00 2.00 3.00

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

// 三次多项式函数
double f(double p, double q, double r, double s, double x) {
    return ((p * x + q) * x + r) * x + s;
}

int main() {
    double p, q, r, s;
    cin >> p >> q >> r >> s;

    vector<double> roots;
    double left = -100, right = 100;
    double step = 0.5;

    // 扫描寻找变号区间
    for (double x = left; x < right && roots.size() < 3; x += step) {
        double y1 = f(p, q, r, s, x);
        double y2 = f(p, q, r, s, x + step);

        if (y1 == 0) { // 精确根
            roots.push_back(x);
        } else if (y1 * y2 < 0) { // 出现符号变化，区间内有根
            double l = x, r2 = x + step;
            // 二分法
            while (r2 - l > 1e-7) {
                double mid = (l + r2) / 2;
                if (f(p, q, r, s, l) * f(p, q, r, s, mid) <= 0)
                    r2 = mid;
                else
                    l = mid;
            }
            roots.push_back((l + r2) / 2);
        }
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < roots.size(); i++) {
        cout << roots[i];
        if (i != 2) cout << " "; 
    }
    cout << endl;

    return 0;
}
