#include <iostream>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || !cloned) return nullptr;
        if (target->val == cloned->val) return cloned;
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left;
        return getTargetCopy(original->right, cloned->right, target);
    }
};