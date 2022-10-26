struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val (x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    int size = 0;
    ListNode *cur = head;
    while(cur) {
        ++size;
        cur = cur->next;
    }
    if (size==1) return nullptr;
    size = size/2;
    cur = head;
    ListNode *prev = nullptr;
    for(int i=0; i<size; ++i) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    return head;
}