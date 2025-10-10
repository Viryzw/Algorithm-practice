// Description: S(0) = moo; S(k) = S(k-1) + m + (k+2)o + S(k-1) 直到字符串长度不小于N，问第N个字符是m还是o
// Input: 一个正整数N
// Output: 一个字符，m或o
// Sample 1
// Input: 11      Output: m
// Sample 2
// Input: 2      Output: 6

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// vector<int> index_m;

// long long getLen(long long k) {
//     if (k == 0) {
//         return 3;
//     }
//     else {
//         return 2 * getLen(k-1) + k + 3;
//     }
// }

// int getNums(long long k) {
//     if (k == 0) {
//         return 1;
//     }
//     else {
//         return 2 * getNums(k - 1) + 1;
//     }
// }

// void buildIndex(long long k) {
//     long long len = getLen(k);
//     if (k == 0) {
//         index_m.push_back(0);
//     }
//     else {
//         auto maxone = max_element(index_m.begin(), index_m.end());
//         index_m.push_back(*maxone + 3);
//     }

//     vector<int> current = index_m;

//     for (int x: current) {
//         if (x != 0) {
//             index_m.push_back(len - x);
//         }
//     }
// }

// int main()
// {
//     long long N;
//     cin >> N;

//     long long k = 0;
//     long long len = getLen(k);
//     while (len < N) {
//         k++;
//         len = getLen(k);
//     }

//     int nums_m = getNums(k);

//     for (int i = 0; i <= k; i++) {
//         buildIndex(i);
//     }

//     bool flag = false;

//     for (int x: index_m) {
//         if (x == N - 1) {
//             flag = true;
//         }
//     }

//     if (flag) {
//         cout << "m" << endl;
//     }
//     else {
//         cout << "o" << endl;
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

long long getLen(long long k) {
    if (k == 0) {
        return 3;
    }
    return 2 * getLen(k - 1) + k + 3;
}

char solve(long long k, long long n) {
    if (k == 0) {
        return n == 1 ? 'm' : 'o';
    }

    long long len_prev = getLen(k - 1);
    long long mid_len = k + 3;

    if (n <= len_prev)
        return solve(k - 1, n);
    else if (n == len_prev + 1)
        return 'm';
    else if (n <= len_prev + mid_len)
        return 'o';
    else
        return solve(k - 1, n - len_prev - mid_len);
}

int main() {
    long long N;
    cin >> N;

    long long k = 0;
    while (getLen(k) < N) k++;

    cout << solve(k, N) << endl;
    return 0;
}
