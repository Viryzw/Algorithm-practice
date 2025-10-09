// Description: Stan先手，Ollie后手，给定两个正整数M，N（<2^31），轮到当前玩家时需将较大数减去较小数的整数倍，先出现(x,0)的选手获胜，两人都会给出最优策略
// Input：第一行包含一个整数C，表示测试组数
// 接下来C行，每行包含两个正整数M和N，表示游戏的初始数字对
// Output：Stan获胜则输出Stan wins，反之输出Ollie wins
// Sample 1
// Input: 2 \\ 25 7 \\ 24 15     Output: Stan wins \\ Ollie wins
// Sample 2
// Input: 1 \\ 1 1      Output: Stan wins

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

bool solution(long long M, long long N) {
    if (M < N) {
        swap(M, N);
    }

    if (N == 0) {
        return false;
    }

    if (M % N == 0 || M / N >= 2) {
        return true;
    }

    return !solution(N, M - N);
}

int main()
{
    int C;
    long long M, N;
    vector<bool> answer;

    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> M >> N;
        answer.push_back(solution(M, N));
    }

    for (int x: answer) {
        if (x) {
            cout << "Stan wins" << endl;
        }
        else {
            cout << "Ollie wins" << endl;
        }
    }
    return 0;
}