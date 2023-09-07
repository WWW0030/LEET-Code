#include "bits/stdc++.h"
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//cur 2 last 1 counter 2
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) return NULL;
        if (left == right) return head;
        int counter = 1;
        ListNode* curPointer = head;
        ListNode* lastNode = NULL;
        // Finding starting point
        while (counter != left) {
            lastNode = curPointer;
            curPointer = curPointer->next;
            counter++;
        }
        ListNode* segmentOne = lastNode;
        ListNode* segmentTwoBegin = curPointer;
        lastNode = curPointer;
        curPointer = curPointer->next;
        counter++;
        while (counter != right) {
            ListNode* tempNode = curPointer->next;
            curPointer->next = lastNode;
            lastNode = curPointer;
            curPointer = tempNode;
            counter++;
        }
        ListNode* segmentThreeBegin = curPointer->next;
        curPointer->next = lastNode;            
        ListNode* segmentTwoEnd = curPointer;
        segmentTwoBegin->next = segmentThreeBegin;        
        if (left == 1) return segmentTwoEnd;
        segmentOne->next = segmentTwoEnd;
        return head;            
    }
};