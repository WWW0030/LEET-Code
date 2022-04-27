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

int *search(struct hash T, int k) {
    // Find the module which will determine which one of the linked list
    int modu = k % T.size;
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
    return NULL;
}

void add(struct hash T, int k) {
    int modu = k % T.size;
    struct anode *new = malloc(sizeof(struct anode));
    (*new).value = k;
    (*new).next = (*T.table[modu]).next;
    (*new).key = k;
    (*(T.table)[modu]).next = new;
}

void delete(struct hash T, int k) {
    int modu = k % T.size;
    struct anode *prev = NULL;
    struct anode *pointer = T.table[modu];
    while((*pointer).next != NULL) {
        if(k == (*pointer).key) {
            struct anode *temp = pointer;
            pointer = (*pointer).next;
            (*prev).next = pointer;
            free((*temp).value);
            free(temp);
        }
        else {
            prev = pointer;
            pointer = (*pointer).next;
        }
    }
    if (k == (*pointer).key) {
        (*prev).next = NULL;
        free((*pointer).value);
        free(pointer);
    }
}

int firstMissingPositive(int* nums, int numsSize){
    struct hash t = make_table(10000);
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0 && search(t, nums[i]) == NULL) add(t, nums[i]);
    }
    int counter = 1;
    while(search(t, counter) != NULL) ++counter;
    return counter;
}