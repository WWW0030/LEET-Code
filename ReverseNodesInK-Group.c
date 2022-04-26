#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int sizeofNode(struct ListNode* head) {
    struct ListNode *curPointer = head;
    int counter = 0;
    while(curPointer != NULL) {
        ++counter;
        curPointer = (*curPointer).next;
    }
    return counter;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int listSize = sizeofNode(head);
    struct ListNode 
    *curPointer = head, *start, *prevTail = start, *curTail, *curHead, *prev, *curr, *next, *temp;
    int counter = k;
    while (listSize >= k) {
        curTail = curPointer;
        curHead = curPointer;
        prev = curPointer;
        curPointer = (*curPointer).next;
        --counter;
        while(counter != 0) {
            curr = curPointer;
            next = (*curPointer).next;
            (*curr).next = prev;
            curHead = curPointer;
            curPointer = next;
            --counter;
            prev = curr;
        }
        if (start == NULL) {
            start = curHead;
            prevTail = curTail;
        }
        else {
            (*prevTail).next = curHead;
            prevTail = curTail;
        }
        counter = k;
        listSize = listSize - k;
    }
    (*prevTail).next = curPointer;
    return start;
}

void printList(struct ListNode *start) {
    struct ListNode *curpointer = start;
    while(curpointer != NULL) {
        printf("%d", (*curpointer).val);
        curpointer = (*curpointer).next;
    }
}

int main() {
    struct ListNode *a = malloc(sizeof(struct ListNode));
    struct ListNode *b = malloc(sizeof(struct ListNode));
    struct ListNode *c = malloc(sizeof(struct ListNode));
    struct ListNode *d = malloc(sizeof(struct ListNode));
    (*a).val = 1;
    (*a).next = b;
    (*b).val = 2;
    (*b).next = c;
    (*c).val = 3;
    (*c).next = d;
    (*d).val = 4;
    (*d).next = NULL;
    struct ListNode *ans = reverseKGroup(a, 4);
    printList(ans);
}