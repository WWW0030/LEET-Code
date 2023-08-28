 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        } 
        else if (!root->left) {
            return 1 + minDepth(root->right);
        }
        else if (!root->right) {
            return 1 + minDepth(root->left);
        }
        else {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
    }
};