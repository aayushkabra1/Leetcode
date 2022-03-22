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

    int getLevel(TreeNode *currentNode, int value, int currentLevel) {
        if (currentNode == nullptr) return -1;
        if (currentNode->val == value) return currentLevel;
        return max(getLevel(currentNode->left, value, currentLevel + 1), getLevel(currentNode->right, value, currentLevel + 1));
    }

    TreeNode * LCA(TreeNode *root, int x, int y) {
        if (root == nullptr) return nullptr;
        if (root->val == x || root->val == y) return root;

        TreeNode *left = LCA(root->left, x, y);
        TreeNode *right = LCA(root->right, x, y);

        if (left && right) return root;
        if (!left) return right;
        return left;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *lca = LCA(root, x, y);
        int height1 = getLevel(lca, x, 0);
        int height2 = getLevel(lca, y, 0);
        return ((height1 > 1 || height2 > 1) && (height1 == height2));
    }
};