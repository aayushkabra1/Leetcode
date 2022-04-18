#include <TreeNode.cpp>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<TreeNode *> vec;

    void inOrder(TreeNode *root) {
        if (!root) return;
        inOrder(root->left);
        vec.push_back(root);
        inOrder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
        return vec[k - 1]->val;
    }
};