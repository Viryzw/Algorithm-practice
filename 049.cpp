// Description: target[i]表示轨迹上第i个位置的高度值；初始轨迹高度值均为0，表示为initial，其长度为target
// 可以选择任意连续的一段位置（子数组），将该子数组的高度同时增加1
// 计算最少几次操作可以使 initial 为 target
// Input: 一个整数数组target，空格隔开
// Output: 一个整数，表示最少操作次数
// Sample 1
// Input: 1 2 3 2 1     Output: 3
// Sample 2
// Input: 3 1 1 2      Output: 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> target;
    int x;
    while (ss >> x) target.push_back(x);

    int operations = 0;
    int prev = 0; // initial heights are all 0

    for (int h : target) {
        if (h > prev) 
            operations += (h - prev);
        prev = h;
    }

    cout << operations << endl;
    return 0;
}
