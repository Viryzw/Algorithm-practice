// Description: 在一个采集的数据列表中，大部分数据都是“正常值”，只有两个数据是例外：其中一个是这些“正常值”的总和，另一个则是异常值。
// 异常值不同于正常值，它既不是原始数据中的任何一个数字，也不是这些正常值的和。
// 你需要找到最大可能的异常值
// Input: 第一行的输入包含一个正整数n（n<=10000），表示采集的数据列表的长度；第二行的输入包含n个整数（范围在-1000~1000之间），表示所采集的数据
// Output: 输出为True或False
// Sample 1
// Input: 3 \\ 2 2 -3      Output: -3
// Sample 2
// Input: 4 \\ 2 3 5 100      Output: 100

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int solution(vector<int>& nums) {
    // 计算所输入数的总和
    long long S = 0;
    for (int i: nums) {
        S += i;
    }

    int maxBad = -1000;
    unordered_set<int> numsSet(nums.begin(), nums.end()); 

    for (int i: nums) {
        if (numsSet.count(S - 2 * i) && S - 2 * i > maxBad) {
            maxBad = S - 2 * i;
        }
    }
    return maxBad;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << solution(arr) << endl;
    return 0;
}