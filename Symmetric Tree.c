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

bool Mirrored(struct TreeNode *p, struct TreeNode *q) {
    if(p == NULL) return (q == NULL);
    if(q == NULL) return (p == NULL);
    return (p->val == q->val) &&  Mirrored(p->left, q->right) && Mirrored(p->right, q->left);
}


bool isSymmetric(struct TreeNode* root){
    if (root==NULL) return true;
    return Mirrored(root->left, root->right);
}