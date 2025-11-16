// Description: 找出若干天的盈利周期，使这段周期的总收益最大，并返回最大收益
// Input: 输入多个整数，以空格隔开，表示过去一段时间内每日的盈利情况
// Output: 输出一个整数，表示最大收益值
// Sample 1
// Input: -2 1 -3 4 -1 2 1 -5 4      Output: 6
// Sample 2
// Input: 5 4 -1 7 8      Output: 23

#include<bits/stdc++.h>

using namespace std;


int main()
{
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> nums;
    int x;

    while(ss >> x) {
        nums.push_back(x);
    }

    int max_ending_here = 0;
    int max_so_far = INT_MIN;

    for (int v: nums) {
        max_ending_here = max(v, max_ending_here + v);

        max_so_far = max(max_so_far, max_ending_here);
    }

    cout << max_so_far << endl;

    return 0;

}