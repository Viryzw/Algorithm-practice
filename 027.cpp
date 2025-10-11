// Description: 求1⨁2⨁⋯⨁N的值，⨁按位异或
// Input: 一个整数N
// Output: 一个整数，表示结果
// Sample 1
// Input: 3      Output: 0
// Sample 2
// Input: 10     Output: 11


#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long ans;
    switch (N % 4) {
        case 0: ans = N; break;
        case 1: ans = 1; break;
        case 2: ans = N + 1; break;
        case 3: ans = 0; break;
    }

    cout << ans << endl;
    return 0;
}
