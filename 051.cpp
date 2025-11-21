// Description: n级台阶，一次上1级或2级，计算有几种方法
// Input: 一个正整数n表示楼梯数量，1<=n<=45
// Output: 一个整数表示楼梯的爬法数
// Sample 1
// Input: 2     Output: 2
// Sample 2
// Input: 3     Output: 3

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 2 << endl;
        return 0;
    }

    int a = 1, b = 2;
    int c;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    cout << b << endl;
    return 0;
}
