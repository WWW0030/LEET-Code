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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Finding list size
        int sizeCounter = 0;
        ListNode* curPointer = head;
        while (curPointer != NULL) {
            curPointer = curPointer->next;
            sizeCounter++;
        }
        int remainder = sizeCounter % k;
        int size = sizeCounter / k;
        // Making the list
        vector<ListNode*> returnVector (k);
        int curSizeCounter = 0;
        curPointer = head;
        for (int i = 0; i < k; i++) {
            curSizeCounter = 0;
            if (i < remainder) {
                returnVector[i] = curPointer;
                while (curSizeCounter < size) {
                    curPointer = curPointer->next;
                    curSizeCounter ++;
                }
                if (curPointer != NULL) {
                    ListNode* tempPointer = curPointer;
                    curPointer = curPointer->next;
                    tempPointer->next = NULL;                    
                }
            }
            else {
                returnVector[i] = curPointer;
                while (curSizeCounter < size - 1) {
                    curPointer = curPointer->next;
                    curSizeCounter ++;
                }
                if (curPointer != NULL) {
                    ListNode* tempPointer = curPointer;
                    curPointer = curPointer->next;
                    tempPointer->next = NULL;                    
                }
            }
        }
        return returnVector;
    }
};