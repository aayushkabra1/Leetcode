#include<iostream>
#include<vector>
#include <queue>
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

class CBTInserter {
public:
    TreeNode *root;
    queue<TreeNode *> q;
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
    }
    
    int insert(int val) {
        TreeNode *p = q.front();
        TreeNode *last = p;

        if (p->left && p->right) {
            while(p->left && p->right) {
                q.push(p->left);
                q.push(p->right);
                q.pop();
                p = q.front();
            }
            last = p;

            if (p->left == nullptr && p->right == nullptr) {
                p->left = new TreeNode(val);
                q.push(p->left);
            }
            else if (p->left == nullptr) {
                p->left = new TreeNode(val);
                q.push(p->left);
                q.push(p->right);
                q.pop();
            }
            else {
                p->right = new TreeNode(val);
                q.push(p->left);
                q.push(p->right);
                q.pop();
            }
        }
        else if (p->left) {
            p->right = new TreeNode(val);
        }
        else if (p->right) {
            p->left = new TreeNode(val);
        }
        else p->left = new TreeNode(val);
        return last->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};