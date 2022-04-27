#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode *alist, struct ListNode *blist) {
    struct ListNode *aPointer = alist;
    struct ListNode *bPointer = blist;
    if(aPointer == NULL && bPointer == NULL) {
        return NULL;
    }
    else if(aPointer == NULL) {
        return bPointer;
    }
    else if (bPointer == NULL) {
        return aPointer;
    }
    struct ListNode *ans = NULL;
    if((*aPointer).val > (*bPointer).val) {
        ans = bPointer;
        bPointer = (*bPointer).next;
    }
    else {
        ans = aPointer;
        aPointer = (*aPointer).next;
    }
    struct ListNode *ansPointer = ans;
    while(aPointer != NULL && bPointer != NULL) {
        int a = (*aPointer).val;
        int b = (*bPointer).val;
        if (a > b) {
            (*ansPointer).next = bPointer;
            bPointer = (*bPointer).next;
            ansPointer = (*ansPointer).next;
        }
        else {
            (*ansPointer).next = aPointer;
            aPointer = (*aPointer).next;
            ansPointer = (*ansPointer).next;
        }
    }
    if (aPointer == NULL) {
        (*ansPointer).next = bPointer;
    }
    else if (bPointer == NULL) {
        (*ansPointer).next = aPointer;
    }
    return ans;
}