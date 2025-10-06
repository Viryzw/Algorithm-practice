// Description: 在程序中定义一函数right(n,k)，它能分离出整数n从右边数第k个数字。
// Input: 正整数n和k
// Output: 一个整数。
// Sample 1
// Input: 72645 2      Output: 4
// Sample 2
// Input: 918273 5      Output: 1

#include<iostream>
using namespace std;

int solution(long long n, long long k) {
    // 欲分离从右数第k个数字，只需做k-1次右移，然后模10
    for (int i = 0; i < k - 1; i++) {
        n /= 10;
    }
    return n % 10;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    cout << solution(n, k) << endl;
    return 0;
}

