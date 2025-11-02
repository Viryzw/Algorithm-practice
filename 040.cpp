// Description: 找出一个正整数n，计算从0到n中每一个数的二进制形式包含的1的个数，将这些1的个数存在一个长度为n+1的数组中输出
// Input: 输入一个正整数
// Output: 输出一个数组（无空格）
// Sample 1
// Input: 2      Output: 012
// Sample 2
// Input: 3      Output: 0112

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> bits(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        bits[i] = bits[i >> 1] + (i & 1);
    }

    // 输出（无空格）
    for (int i = 0; i <= n; i++) {
        cout << bits[i];
    }
    cout << endl;

    return 0;
}
