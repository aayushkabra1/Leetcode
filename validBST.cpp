#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool isValidBSTUtil(TreeNode *root, int min, int max) {
        if (root == nullptr) return true;
        if (root->val < min || root->val > max) return false;
        return isValidBSTUtil(root->left, min, root->val - 1) && isValidBSTUtil(root->right, root->val + 1, max);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, INT_MIN, INT_MAX);

    }
};

