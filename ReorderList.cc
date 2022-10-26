#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val (x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    vector<ListNode *> list;
    ListNode *cur = head;
    int size = 0;
    while(cur) {
        ++size;
        list.push_back(cur);
        cur = cur->next;
    }
    if (size==1) return;
    for(int i=0; i<size/2; ++i) {
        list[i]->next = list[size-1-i];
        list[size-1-i]->next = list[i+1];
    }
    list[size/2]->next = nullptr;
}