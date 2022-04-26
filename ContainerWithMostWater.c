#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize){
    int size, max = 0, left = 0, right = heightSize - 1;
    while (left != right) {
        size = (right - left) * fmin(height[left], height[right]);
        if (size > max) max = size;
        if (height[left] < height[right]) ++left;
        else --right;
    }
    return max;
}