// Description: 当三个号码中，存在一个号码等于另外两个（不同的）号码之和时符合条件。判断有几种符合条件的情况。
// Input: 第一行输入包含一个整数n（3≤n≤500），表示抽奖盒内的号码个数，第二行有n个正整数，表示抽奖号码（抽奖号码各不相同）
// Output: 一个正整数，表示有多少种满足抽奖条件的情况。
// Sample 1
// Input: 3 \\ 1 2 3      Output: 1
// Sample 2
// Input: 4 \\ 1 2 3 4    Output: 2

#include<iostream>
#include<algorithm>
using namespace std;

int solution(int n, int a[]) {
    // 首先对数组进行排序
    sort(a, a + n);

    int count = 0;
    
    // 对于每个可能的和（即目标值）
    for (int k = 2; k < n; k++) {
        int target = a[k];
        int left = 0;
        int right = k - 1;
        
        // 使用双指针技术在a[0]到a[k-1]中寻找两数之和等于target
        while (left < right) {
            int sum = a[left] + a[right];
            if (sum == target) {
                count++;
                break;
            } 
            else if (sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }
    }
    
    return count;
}

int main() {
    int n;
    int a[505];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solution(n, a) << endl;
    return 0;
}