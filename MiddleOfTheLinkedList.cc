struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val (x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    int size = 0;
    ListNode *cur = head;
    while(cur) {
        ++size;
        cur = cur->next;
    }
    size = size/2;
    cur = head;
    for(int i=0; i<size; ++i) {
        cur = cur->next;
    }
    return cur;
}