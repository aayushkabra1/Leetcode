#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
        vector<int> ans;
        queue<Node *> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            Node *temp = q.front();
            q.pop();
            if (temp != nullptr) {
                if (q.front() == nullptr) ans.push_back(temp->data);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            } else if (!q.empty()) {
                q.push(nullptr);
            }
        }
        return ans;
    }
};

