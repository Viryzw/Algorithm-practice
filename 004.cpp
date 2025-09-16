// Description: 鸡m元、鸭t元、共n元
// Input: 输入一行三个正整数，表示你持有的钱数n和鸡鸭的价格m、t，用空格分隔（三个正整数均不大于1000000）。
// Output: 一个整数，表示所有可能的购买组合方式的数目
// Sample 1
// Input: 20 10 5      Output: 9
// Sample 2
// Input: 5 10 10    Output: 1

#include<iostream>
using namespace std;

long long solution(int n, int m, int t) {
    long long count = 0;
    for (int x = 0; x <= n / m; x++) {
        int remain = n - m * x;
        count += (remain / t) + 1;
    }
    return count;
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
	cout << solution(n, m, t) << endl;
    return 0;
}