#include "bits/stdc++.h"
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* oriHead = head;
        // Find the size of the list first
        ListNode* curPointer = head;
        int size = 0;
        while (curPointer != NULL) {
            curPointer = curPointer->next;
            size++;
        }
        if (size == 0) return head;
        // Calculate the new head of the list
        int remainder = k % size;
        if (remainder == 0) return head;
        int newHeadInd = size - remainder;
        curPointer = head;
        ListNode* lastPointer = NULL;
        // Find the new head and manipulate list
        for (int i = 0; i < newHeadInd; ++i) {
            lastPointer = curPointer;
            curPointer = curPointer->next;
        }
        lastPointer->next = NULL;
        ListNode* newHead = curPointer;
        // Find the tail and concatenate original head
        while(curPointer->next != NULL) {
            curPointer = curPointer->next;
        }
        curPointer->next = oriHead;
        return newHead;
    }
};