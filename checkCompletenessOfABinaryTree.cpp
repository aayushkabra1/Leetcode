#include <iostream>
#include <vector>
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

    bool isCompleteUtil(TreeNode *root, int index, int &count) {
        if (root == nullptr) return true;
        if (index >= count) return false;
        return isCompleteUtil(root->left, 2*index + 1, count) && isCompleteUtil(root->right, 2*index + 2, count);
    }

    bool isCompleteTree(TreeNode* root) {
        int count = countNode(root);
        return isCompleteUtil(root, 0, count);
    }

    int countNode(TreeNode *root) {
        return (root == nullptr) ? 0 : 1 + countNode(root->left) + countNode(root->right);
    }
};