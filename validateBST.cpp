#include <iostream>
#include <climits>
#include <TreeNode.cpp>
using namespace std;

class Solution {
public:
    bool util(TreeNode *root, long long max, long long min) {
        if (!root) return true;
        if (root->val > min && root->val < max) {
            return util(root->left, root->val, min) && util(root->right, max, root->val);
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return util(root, LLONG_MAX, LLONG_MIN);
    }
};