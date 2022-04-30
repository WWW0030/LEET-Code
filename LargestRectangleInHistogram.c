#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *push(struct ListNode *stack, int val) {
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    (*newNode).val = val;
    (*newNode).next = stack;
    return newNode;
}

int peek(struct ListNode *stack) {
    return (*stack).val;
}

struct ListNode *pop(struct ListNode *stack) {
    struct ListNode *temp = stack;
    stack = (*stack).next;
    free(temp);
    return stack;
}

bool isEmpty(struct ListNode *stack) {
    return (stack == NULL);
}

void printArray(int array[], int size) {
    for(int i = 0; i < size; ++i) printf("%d", array[i]);
}

int largestRectangleArea(int* heights, int heightsSize){
    //leftBound[i] and RightBound[i] are the indexs which can form the largest rectangle of height heights[i]. 
    struct ListNode *prevBound = NULL;
    int leftBound[heightsSize];
    for (int i = 0; i < heightsSize; ++i) {
        //Remove all past elements larger than the current, since the current restricts the size of any larger
        while(!isEmpty(prevBound) && heights[peek(prevBound)] >= heights[i]) prevBound = pop(prevBound);
        //Current is the smallest of all past
        if(isEmpty(prevBound)) leftBound[i] = 0;
        //Else, we found the leftBound, an element smaller than current
        else leftBound[i] = peek(prevBound) + 1;
        prevBound = push(prevBound, i);
    }
    //Opposite of prevBound
    struct ListNode *nextBound = NULL;
    int rightBound[heightsSize];
    for (int i = heightsSize - 1; i >=0; --i) {
        while(!isEmpty(nextBound) && heights[peek(nextBound)] >= heights[i]) nextBound = pop(nextBound);
        if(isEmpty(nextBound)) rightBound[i] = heightsSize - 1;
        else rightBound[i] = peek(nextBound) - 1;
        nextBound = push(nextBound, i);
    }
    printArray(leftBound, heightsSize);
    printf("\n");
    printArray(rightBound, heightsSize);
    int max = 0, area;
    for(int i = 0; i < heightsSize; ++i) {
        area = (rightBound[i] - leftBound[i] + 1) * heights[i];
        printf("%d", area);
        if (area > max) max = area;
    }
    return area;
}