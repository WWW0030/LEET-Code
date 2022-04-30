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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL) return (q == NULL);
    else if (q==NULL) return (p == NULL);
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}