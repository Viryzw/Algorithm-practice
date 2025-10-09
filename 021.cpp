// Description: 输入一组数字序列，0为结束标志，然后倒序输出，0不需要输出
// Input：一行内输入一串整数，以0结束，以空格间隔，（0<=i<=2^31-1）不超过100个
// Output：一行内倒序输出这串整数，空格间隔
// Sample 1
// Input: 8 42 17 9 56 2 70 0     Output: 70 2 56 9 17 42 8
// Sample 2
// Input: 5 7 9 11 2 3 8 9 0      Output: 9 8 3 2 11 9 7 5

#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<long long> nums;
    long long temp;
    while(1) {
        cin >> temp;
        if (temp == 0) {
            break;
        }
        nums.push_back(temp);
    }

    for (int i = nums.size() - 1; i >= 0; i--) {
        cout << nums[i];
        if (i != 0) cout << " "; // 只有不是最后一个才输出空格
    }

    cout << endl; // 最后换行
    return 0;
}