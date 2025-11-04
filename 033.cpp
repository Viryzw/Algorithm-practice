// Description: 现有一个由正整数组成且没有重复元素的数组，如果数组元素顺序是二叉搜索树的先序遍历序列，则返回true，否则false
// Input: 输入一个没有重复元素的整数数组
// Output: 输出true或者false
// Sample 1
// Input: 17 14 12 3 6 9 16 20      Output: true
// Sample 2
// Input: 17 12 14 3 6 9 16 20      Output: false

#include<iostream>
#include<vector>
#include<sstream>
#include<stack>
#include<climits>

using namespace std;

bool solution(const vector<int>& vals) {
    stack<int> st;
    int lower_bound = INT_MIN;

    for (int val : vals) {
        if (val < lower_bound) return false; // 违反BST性质

        while (!st.empty() && val > st.top()) {
            lower_bound = st.top();
            st.pop();
        }
        st.push(val);
    }
    return true;
}


int main()
{
    vector<int> vals;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while(ss >> num) {
        vals.push_back(num);
    }

    cout << (solution(vals) ? "true" : "false") << endl;
    return 0;
}