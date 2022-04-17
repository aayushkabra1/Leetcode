#include <iostream>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    vector<TreeNode *> inOrderVector;

    void inOrder(TreeNode *root) {
        if (!root) return;
        inOrder(root->left);
        inOrderVector.push_back(root);
        inOrder(root->right);
        root->left = root->right = nullptr;
    }

    TreeNode* increasingBST(TreeNode* root) {
        inOrder(root);
        int n = inOrderVector.size();
        for (int i = 0; i < n - 1; i++) {
            inOrderVector[i]->right = inOrderVector[i + 1];
        }
        return inOrderVector[0];
    }
};