/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
// Less than O(n^2) solution:
// Implement Hashtable
// All elements pass through put into hashtable
// When get a new element, check if the counter part is in the hashtable O(n) solution
// Constant time to access hashtable

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int bot = 0;
    while(true) {
        for (int i = bot + 1; i < numsSize; ++i) {
            if (nums[bot] + nums[i] == target) {
                int *ans = malloc(sizeof(int) * 2);
                ans[0] = bot;
                ans[1] = i;
                *returnSize = 2;
                return ans;
            }
        }
        ++bot;
    }
}