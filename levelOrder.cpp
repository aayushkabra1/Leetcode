#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        vector<int> temp;
        queue<Node *> q;
        q.push(root);
        q.push(nullptr);

        while(!q.empty()) {
            Node *p = q.front();
            q.pop();

            if (p != nullptr) {
               temp.push_back(p->val);
                for (Node *n : p->children) {
                    q.push(n);
                }
            }

            else {
                if (!q.empty()) {
                    q.push(nullptr);
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

