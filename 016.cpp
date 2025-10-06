// Description: m个苹果分配到n个盘子，允许空，计算分法总数
// Input: 第一行包含一个整数t，表示测试数据的数量
// 接下来t行每行包含两个整数m，n，表示苹果数和盘子数，保证1<=m,n<=10, 0<=t<=20
// Output: 对于每组数据输出分法数量
// Sample 1
// Input: 1 \\ 7 3      Output: 8
// Sample 2
// Input: 3 \\ 3 2 \\ 4 3 \\ 2 7      Output: 2 \\ 4 \\ 2

#include<iostream>
#include<vector>

using namespace std;

#define MAXN 15

long long dp[MAXN][MAXN]; // 题目中 m,n <= 10，够用了

long long solution(int m, int n) {
    if (m == 0 || n == 1) return 1;
    if (dp[m][n] != -1) return dp[m][n]; // 已计算过

    if (m < n)
        dp[m][n] = solution(m, m);
    else
        dp[m][n] = solution(m, n - 1) + solution(m - n, n);
    return dp[m][n];
}

int main()
{
    int t, m, n;
    cin >> t;
    vector<long long> answer;

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++) {
            dp[i][j] = -1;
        }

    for (int i = 0; i < t; i++) {
        cin >> m >> n;
        answer.push_back(solution(m, n));
    }

    for (long long x: answer) {
        cout << x << endl;
    }
    return 0;
}