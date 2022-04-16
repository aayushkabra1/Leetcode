#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int total = 0;
    void util(TreeNode *root) {
        if (!root) return;
        util(root->right);
        total += root->val;
        root->val = total;
        util(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        util(root);
        return root;
    }
};