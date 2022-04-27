#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct anode {
  int key;
  int value;
  struct anode *next;
}; 

struct hash {
    int size;
    struct anode **table;
};

struct hash make_table(int s) {
    // Make the struct which will be returned
    struct hash new;
    // Seet the size to s
    new.size = s;
    // Malloc enough space for the table
    struct anode **list = malloc(sizeof(struct anode*) * s);
    new.table = list;
    for (int i = 0; i < s; ++i) {
        // Malloc an anode for each element of the array
        struct anode *newlist = malloc(sizeof(struct anode));
        // Set each next of the newlist to NULL;
        // These anodes will act as a buffer, which makes coding functions simple
        (*newlist).next = NULL;
        // Set each element to these newlists
        new.table[i] = newlist;
    }
    return new;
}

int search(struct hash T, int k) {
    // Find the module which will determine which one of the linked list
    int modu = k % T.size;
    if(modu < 0) modu = modu * -1;
    // pointer to the first element of the selected linked list
    // Rememebr this is the buffer anode
    struct anode *pointer = T.table[modu];
    // While there are more elements inside of the anode,
    while((*pointer).next != NULL) {
        if(k == (*pointer).key) {
            return (*pointer).value;
        }
        pointer = (*pointer).next;
    }
    // Lastly, check the last element
    if (k == (*pointer).key) {
        return (*pointer).value;
    }
    return 1000000001;
}

void add(struct hash T, int k, int v) {
    int modu = k % T.size;
    if (modu < 0) modu = modu * -1;
    struct anode *new = malloc(sizeof(struct anode));
    (*new).value = v;
    (*new).next = (*T.table[modu]).next;
    (*new).key = k;
    (*(T.table)[modu]).next = new;
}

int *twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct hash t = make_table(10);
    add(t, nums[0], 0);
    for (int i = 1; i < numsSize; ++i) {
        if (search(t, target - nums[i]) != 1000000001) {
            int *ans = malloc(sizeof(int) * 2);
            ans[0] = search(t, target - nums[i]);
            ans[1] = i;
            *returnSize = 2;
            return ans;
        }
        add(t, nums[i], i);
    }
    return NULL;
}