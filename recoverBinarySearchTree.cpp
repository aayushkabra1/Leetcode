#include <iostream>
#include "TreeNode.cpp"
#include <climits>
using namespace std;

class Solution {
public:
    TreeNode *first, *second, *prev;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (root->val < prev->val && !first) {
            first = prev;
        }
        if (root->val < prev->val && first) {
            second = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val, second->val);
    }
};