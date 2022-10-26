#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {
    vector<int> list;
    int size = 0;
    ListNode *cur = head;
    while(cur) {
        ++size;
        list.push_back(cur->val);
        cur = cur->next;
    }
    int max = 0;
    for (int i=0; i<size/2; ++i) {
        int current;
        current = list[i] + list[size-i-1];
        if (current > max) max = current;
    }
    return max;
}