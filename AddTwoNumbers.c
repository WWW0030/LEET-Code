/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *OnePointer = l1;
    struct ListNode *TwoPointer = l2;
    struct ListNode *ans = NULL;
    struct ListNode *ansPointer = ans;
    int carry = 0;
    while(true) {
        if(OnePointer == NULL && TwoPointer == NULL) {
            if (carry == 1) {
                struct ListNode *newnode = malloc(sizeof(struct ListNode));
                (*newnode).val = 1;
                (*newnode).next = NULL;
                (*ansPointer).next = newnode;
            }
            return ans;
        }
        else if(OnePointer == NULL) {
            struct ListNode *newnode = malloc(sizeof(struct ListNode));
            if(carry + (*TwoPointer).val < 10) {
                (*newnode).val = carry + (*TwoPointer).val;
                (*newnode).next = NULL;
                carry = 0;
            }
            else {
                (*newnode).val = carry + (*TwoPointer).val - 10;
                carry = 1;
                (*newnode).next = NULL;
            }
            if(ans == NULL) {
                ans = newnode;
                ansPointer = ans;
            }
            else {
                (*ansPointer).next = newnode;
                ansPointer = (*ansPointer).next;  
            }
            TwoPointer = (*TwoPointer).next;
        }
        else if(TwoPointer == NULL) {
            struct ListNode *newnode = malloc(sizeof(struct ListNode));
            if(carry + (*OnePointer).val < 10) {
                (*newnode).val = carry + (*OnePointer).val;
                (*newnode).next = NULL;
                carry = 0;
            }
            else {
                (*newnode).val = carry + (*OnePointer).val - 10;
                carry = 1;
                (*newnode).next = NULL;
            }
            if(ans == NULL) {
                ans = newnode;
                ansPointer = ans;
            }
            else {
                (*ansPointer).next = newnode; 
                ansPointer = (*ansPointer).next;
            }
            OnePointer = (*OnePointer).next;
        }
        else {
            struct ListNode *newnode = malloc(sizeof(struct ListNode));
            if(carry + (*OnePointer).val + (*TwoPointer).val < 10) {
                (*newnode).val = carry + (*OnePointer).val + (*TwoPointer).val;
                (*newnode).next = NULL;
                carry = 0;
            }
            else {
                (*newnode).val = carry + (*OnePointer).val + (*TwoPointer).val - 10;
                (*newnode).next = NULL;
                carry = 1;
            }
            if(ans == NULL) {
                ans = newnode;
                ansPointer = ans;
            }
            else {
                (*ansPointer).next = newnode;
                ansPointer = (*ansPointer).next;  
            }
            OnePointer = (*OnePointer).next;
            TwoPointer = (*TwoPointer).next;
        }        
    }
}