// Description: 通过增加2的某次幂或减少2的某次幂，使输入数在最少次数内归零
// Input: 一个整数n，表示当前设备的能量值 1 <= n <= 10^5
// Output: 一个整数，表示将能量值归零所需的最少操作次数
// Sample 1
// Input: 39      Output: 3
// Sample 2
// Input: 54      Output: 3


#include <iostream>
using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    int ops = 0;
    long long x = n;
    while (x > 0) {
        if ((x & 1) == 0) {
            // even: 这一位为0
            x >>= 1;
        } else {
            // odd: 决定是 +1 还是 -1
            // 若 x%4 == 1 或 x == 3, 选择 -1 (即 x -= 1)
            // 否则（x%4 == 3 且 x != 3），选择 +1 (即 x += 1)
            if ( (x & 3) == 1 || x == 3 ) {
                x -= 1;
            } else {
                x += 1;
            }
            ops++;      // 这一位是非零（+1 或 -1），记一次操作
            x >>= 1;    // 处理完后右移一位
        }
    }

    cout << ops << endl;
    return 0;
}
