// Description: 举个例子，在某些自动验证码系统中，系统可能会要求用户输入一个数字和它的反转之和，以确保输入的不仅仅是简单的数字，而是某种符合规则的组合。
// 现在有一个大于等于 0 的整数n，请你编写程序计算它是否可以由一个数m（m是一个大于等于 0 的整数）与它的反转数相加得到。例如443，存在一个数271，使得271 + 172 = 443。
// Input: 输入包含一个整数n
// Output: 输出为True或False
// Sample 1
// Input: 443     Output: True
// Sample 2
// Input: 63      Output: False

#include <iostream>
using namespace std;

int reverseNum(int m) {
    int rev = 0;
    while (m > 0) {
        rev = rev * 10 + m % 10;
        m /= 10;
    }
    return rev;
}

bool isExist(int num) {
    for (int i = 0; i <= num; i++) {
        if ((i + reverseNum(i)) == num) {
            return true;
        }
    }
    return false;
}

int main()
{
    int num;
    cin >> num;
    if (isExist(num)) {
	cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}
