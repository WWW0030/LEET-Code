/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

bool rightSide(struct TreeNode *root, int min, int max, bool noMin, bool noMax);
bool leftSide(struct TreeNode *root, int min, int max, bool noMin, bool noMax);

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool rightSide(struct TreeNode *root, int min, int max, bool noMin, bool noMax) {
    if(root==NULL) return true;
    printf("%d     %d     %d", root->val, min, max);
    if((root->val <= min && !noMin) || (root->val >= max && !noMax)) return false;
    return leftSide(root->left, min, fmin(root->val, max), noMin, false) && rightSide(root->right, fmax(root->val, min), max, false, noMax);
}

bool leftSide(struct TreeNode *root, int min, int max, bool noMin, bool noMax) {
    if(root==NULL) return true;
    if((root->val <= min && !noMin) || (root->val >= max && !noMax)) return false;
    return leftSide(root->left, min, fmin(root->val, max), noMin, false) && rightSide(root->right, fmax(root->val, min), max, false, noMax);
}

bool isValidBST(struct TreeNode* root){
    if (root==NULL) return true;
    return leftSide(root->left, -INFINITY, root->val, true, false) && rightSide(root->right, root->val, INFINITY, false, true);
}