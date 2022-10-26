#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val (x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    string x = "";
    ListNode *cur = head;
    while(cur != nullptr) {
        x += to_string(cur->val);
        cur = cur->next;
    }
    for (int i = 0; i < x.length()/2; ++i) {
        if(x[i] != x[x.length() - i - 1]) return false;
    }
    return true;
}

int main() {
    ListNode *a = new ListNode(4);
    ListNode *b = new ListNode(4, a);
    ListNode *c = new ListNode(3, b);
    cout << isPalindrome(c);
}