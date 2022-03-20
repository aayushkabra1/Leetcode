#include<iostream>
#include<vector>
#include<stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        stack<TreeNode *> curr;
        stack<TreeNode *> next;
        bool leftToRight = true;
        int level = 0;

        curr.push(root);
        while(!curr.empty()) {
            TreeNode *tempNode = curr.top();
            curr.pop();

            if (tempNode) {
                ans[level].push_back(tempNode->val);
                if (leftToRight) {
                    if (tempNode->left) curr.push(tempNode->left);
                    if (tempNode->right) curr.push(tempNode->right);
                } else {
                    if (tempNode->right) curr.push(tempNode->right);
                    if (tempNode->left) curr.push(tempNode->left);
                }
            }

            if (curr.empty()) {
                leftToRight = !leftToRight;
                swap(curr, next);
                level++;
            }
        }
        return ans;
    }
};