// Input: 输入为一行，包含两个字符串（字符串只包含英文字母和#），用空格分隔
// Output: 输出True或False
// Sample 1
// Input: aaa#d aab#d       Output: True
// Sample 2
// Input: aab#d scsf#d     Output: False

#include <iostream>
using namespace std;

bool isEqual(string S, string T) {
    int ptrS = S.size() - 1;
    int ptrT = T.size() - 1;
    int backCountS = 0;
    int backCountT = 0;

    while (ptrS >= 0 || ptrT >= 0) {
        while (ptrS >= 0) {
            if (S[ptrS] == '#') {
                backCountS++;
                ptrS--;
            }
            else if (backCountS > 0) {
                backCountS--;
                ptrS--;
            }
            else {
                break;
            }
        }

        while (ptrT >= 0) {
            if (T[ptrT] == '#') {
                backCountT++;
                ptrT--;
            }
            else if (backCountT > 0) {
                backCountT--;
                ptrT--;
            }
            else {
                break;
            }
        }

        if (ptrS >= 0 && ptrT >= 0) {
            if (S[ptrS] != T[ptrT]) {
                return false;
            }
        } 
        else {
            if (ptrS >= 0 || ptrT >= 0) {
                return false;   // 有效字符串不等长则false
            }
        }

        ptrS--;
        ptrT--;
    }
    return true;
}

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;

    if (isEqual(s1, s2)) {
	    cout << "True" << endl;
    }

    else {
        cout << "False" << endl;
    }

    return 0;
}