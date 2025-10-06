// Description: 共振阵列由 k 个连续编号的量子环组成，编号从 a 到 a + k - 1。每个编号为 i 的量子环释放能量值为 i。整个阵列的总能量为所有环能量之和。
// 科学家设定一个目标能量值 n，希望知道有多少种不同的连续编号阵列可以精确产生该能量。
// 但有一个宇宙法则：任意共振阵列必须至少包含一个量子环，且编号必须为正整数（即 a ≥ 1, k ≥ 1）。
// 现在，请你编写程序，帮助科学家计算：对于给定的目标能量 n，有多少种不同的连续编号阵列能产生精确等于 n 的总能量？
// Input: 一个正整数n，表示目标总能量
// Output: 一个整数，表示满足条件的连续编号阵列的种数
// Sample 1
// Input: 5      Output: 2
// Sample 2
// Input: 9      Output: 3

#include<iostream>
#include<cmath>
using namespace std;

long long solution(int n) {
    // 根据等差数列求和知，只需k整除n，2整除k-1即可
    long long count = 0;
    for (long long k = 1; k <= sqrt(2 * n) + 1; k++) {
        if ((2 * n - k * (k - 1)) % (2 * k) == 0) {
            if ((2 * n - k * (k - 1)) / (2 * k) > 0) {
                count++;
            }   
        }
    }
    return count;
}

int main()
{
    int n;
    long long count;
    cin >> n;
    count = solution(n);
    cout << count << endl;
    return 0;
}