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
    void invert(TreeNode *root) {
        if (!root) return;
        if (root->left && root->right) {
            invert(root->left);
            invert(root->right);
            swap(root->left, root->right);
            return;
        }
        if (root->left) {
            invert(root->left);
            root->right = root->left;
            root->left = nullptr;
            return;
        }
        if (root->right) {
            invert(root->right);
            root->left = root->right;
            root->right = nullptr;
            return;
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};