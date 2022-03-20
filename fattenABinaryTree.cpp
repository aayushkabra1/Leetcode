#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode *left;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {

        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;

        if (root->left != nullptr) {
            flatten(root->left);
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = nullptr;

            TreeNode *t = root->right;
            while(t->right) t = t->right;
            t->right = temp;
        }
        flatten(root->right);
    }
};
