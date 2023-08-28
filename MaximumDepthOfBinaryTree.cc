#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        } 
        else if (!root->left) {
            return 1 + maxDepth(root->right);
        }
        else if (!root->right) {
            return 1 + maxDepth(root->left);
        }
        else {
            return 1 +  max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};