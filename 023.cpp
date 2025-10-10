// Description: 有三根柱子X、Y、Z，开始时X柱上有2m个拼图板，m种大小，每种2块，自上而下从小到大
// 要从X移到Z，一次移动一块，始终保持自上而下从小到大
// Input: 一个正整数m，表示X柱上初始2m块
// Output: 一个正整数，表示完成移动的最少次数
// Sample 1
// Input: 1      Output: 2
// Sample 2
// Input: 2      Output: 6

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int getIndex(const vector<int>& a) {
    for (int i = a.size()-1; i >= 0; i--) {
        if (a[i] != 0) {
            return i;
        }
    }
    return 0;
}

int main() {
    int m;
    cin >> m;
    vector<int> answer(100);
    answer[0] = 1;
    int a = 0;

    for (int i = 0; i < m+1; i++) {
        for (int j = 0; j < answer.size(); j++) {
            answer[j] = answer[j] * 2 + a;
            a = answer[j] / 10;
            answer[j] = answer[j] % 10;
        }
    }

    int borrow = 2, i = 0;
    while (borrow > 0 && i <= getIndex(answer)) {
        if (answer[i] < borrow) {
            answer[i] = answer[i] + 10 - borrow;
            borrow = 1;
        } else {
            answer[i] -= borrow;
            borrow = 0;
        }
        i++;
    }

    for (int i = getIndex(answer); i >= 0; i--) {
        cout << answer[i];
    }
    cout << endl;
    return 0;
}