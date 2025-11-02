// Description: 有两个链表，每个链表分别表示一个非负整数。该非负整数再链表中逆序存储，链表的每个节点存储一位数字
// 需要用链表节点加和的方式，将两个非负整数相加，并返回一个表示结果的链表
// Input: 输入两个链表
// Output: 输出一个链表
// Sample 1
// Input: 1 2 \\ 3 4      Output: 4 6
// Sample 2
// Input: 9 9 \\ 8 1 9 6 3 4 9 9      Output: 7 1 0 7 3 4 9 9
// Sample 3
// Input: 0 \\ 0      Output: 0

#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* readList() {
    vector<int> vals;
    string line;
    getline(cin, line);
    
    for(int i = 0; i < line.length(); i++) {
        if (line[i] != ' ') {
            vals.push_back(line[i] - '0');
        }
    }

    if (vals.empty()) {
        return new ListNode(0);
    }

    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;

    for (int i = 1; i < vals.size(); i++) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

ListNode* add(ListNode *l1, ListNode *l2) {
    ListNode NewList(0);
    ListNode *cur = &NewList;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1 -> val;
            l1 = l1 -> next;
        }

        if (l2) {
            sum += l2 -> val;
            l2 = l2 -> next;
        }

        carry = sum / 10;
        cur -> next = new ListNode(sum % 10);
        cur = cur->next;
    }

    return NewList.next;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if (head->next) {
            cout << ' ';
        }
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *l1 = readList();
    ListNode *l2 = readList();

    ListNode* res = add(l1, l2);
    printList(res);

    return 0;
}