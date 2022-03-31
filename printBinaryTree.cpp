#include <iostream>
#include <vector>
#include <cmath>
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
    int h;
    int height(TreeNode *root) {
        if (!root) return -1;
        return 1 + max(height(root->left), height(root->right));
    }

    void util(vector<vector<string>> &ans, TreeNode *root, int r, int c) {
        if (!root) return;
        ans[r][c] = to_string(root->val);
        util(ans, root->left, r + 1, c - pow(2, h - 1 - r));
        util(ans, root->right, r + 1, c + pow(2, h - 1 - r));
    }

    vector<vector<string>> printTree(TreeNode* root) {
        h = height(root);
        int m = h + 1;
        int n = pow(2, h + 1) - 1;

        vector<vector<string>> ans(m, vector<string>(n, ""));
        util(ans, root, 0, (n - 1) / 2);
        return ans;
    }
};

