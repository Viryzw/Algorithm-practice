// Description: 这个程序输入两个整数 A 和 B，然后使用欧几里得算法计算它们的最大公约数（GCD），并输出递归调用的次数。
// 你的任务是给定一个整数 K，找到一对整数 A 和 B，使得程序的输出为 K。
// Input: 一个正整数 K，表示期望的递归调用次数。
// Output: 一行，两个正整数A和B。但是，必须满足1<= A,B <= 10^9。
// Sample 1
// Input: 1      Output: 1 1
// Sample 2
// Input: 2      Output: 1 2
// Sample 3
// Input: 16     Output: 987 1597

#include<iostream>
#include<vector>

using namespace std;

vector<long long> solution(long long K) {
    long long a = 1, b = 1;
    for (long long i = 0; i < K - 1; i++) {
        a = a + b;
        b = a - b;
    }

    vector<long long> answer = {b, a};
    return answer;
}

int main()
{
    long long K;
    cin >> K;
    vector<long long> answer = solution(K);
    cout << answer[0] << " " << answer[1] << endl;
}
