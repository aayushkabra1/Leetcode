#include <iostream>
#include "TreeNode.cpp"
#include <vector>
#include <stack>
using namespace std;

// class BSTIterator {
//     void inOrderTrav(TreeNode *root) {
//         if (!root) return;
//         inOrderTrav(root->left);
//         this->inOrder.push_back(root);
//         inOrderTrav(root->right);
//     }

// public:
//     TreeNode *root;
//     int i;
//     vector<TreeNode *> inOrder;
//     BSTIterator(TreeNode* root) {
//         this->root = root;
//         this->i = -1;
//         inOrderTrav(root);
//     }
    
//     int next() {
//         return inOrder[++i]->val;
//     }
    
//     bool hasNext() {
//         int n = inOrder.size();
//         //cout << n << " " << i;
//         return i < (n - 1);
//     }
// };

class BSTIterator {
    stack<TreeNode *> st;
    void push(TreeNode *root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        TreeNode *temp = st.top(); st.pop();
        push(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
