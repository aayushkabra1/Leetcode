#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p && q) {
            bool sameValue = (q->val == q->val);
            bool sameLeftTree = isSameTree(p->left, p->right);
            bool sameRightTree = isSameTree(p->right, q->right);
            return sameValue && sameLeftTree && sameRightTree;
        }
        return false;
    }
};