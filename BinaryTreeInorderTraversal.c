/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sizeTree(struct TreeNode* root) {
    if (root == NULL) return 0;
    return sizeTree((*root).left) + sizeTree((*root).right) + 1;
}

int inorderTraversalHelper(struct TreeNode* root, int index, int* ans) {
    if(root == NULL) return index;
    index = inorderTraversalHelper((*root).left, index, ans);
    ans[index] = (*root).val;
    ++index;
    return inorderTraversalHelper((*root).right, index, ans);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(root == NULL) return NULL;
    int size = sizeTree(root);
    int *ans = malloc(sizeof(int) * size);
    *returnSize = size;
    inorderTraversalHelper(root, 0, ans);
    return ans;
}