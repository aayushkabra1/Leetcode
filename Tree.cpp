#include <iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
public:
    Node *left;
    int data;
    Node *right;
};

class Tree{

    Node *root;
    void preOrderRecursive(Node *p);
    void postOrderRecursive(Node *p);
    void inOrderRecursive(Node *p);

    void preOrderIterative(Node *p);
    void postOrderIterative(Node *p);
    void inOrderIterative(Node *p);

  public:

    Tree() {root = NULL;}
    void createTree();

    void preOrderRecursive() {preOrderRecursive(root);}
    void postOrderRecursive() {postOrderRecursive(root);}
    void inOrderRecursive() {inOrderRecursive(root);}

    void preOrderIterative() {preOrderIterative(root);}
    void postOrderIterative() {postOrderIterative(root);}
    void inOrderIterative() {inOrderIterative(root);}

    void levelOrder();
};

void Tree::createTree() {
    Node *t, *p;
    int x;
    queue<Node *> q;

    cout << "Enter the value of root node: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    q.push(root);

    while(!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter the left child of " << p->data << ": ";
        cin >> x;
        
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->left = t;
            q.push(t);
        }

        cout << "Enter the right child of " << p->data << ": ";
        cin >> x;

        if (x != -1) {
          t = new Node;
          t->data = x;
          t->left = NULL;
          t->right = NULL;
          p->right = t;
          q.push(t);
        }
    }
}

void Tree::preOrderRecursive(Node *p) {
    if(p) {
        cout << p->data << " ";
        preOrderRecursive(p->left);
        preOrderRecursive(p->right);
    }
}

void Tree::postOrderRecursive(Node *p) {
    if (p) {
        postOrderRecursive(p->left);
        postOrderRecursive(p->right);
        cout << p->data << " ";
    }
}

void Tree::inOrderRecursive(Node *p) {
    if (p) {
        inOrderRecursive(p->left);
        cout << p->data << " ";
        inOrderRecursive(p->right);
    }
}

void Tree::preOrderIterative(Node *p) {
    stack<Node *> s;
    while(p || !s.empty()) {
        if (p) {
            cout << p->data << " ";
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void Tree::postOrderIterative(Node* p) {
  stack<Node *> s;
    do {
        while (p) {
        s.push(p->right);
        s.push(p);
        p = p->left;
        }

        p = s.top();
        s.pop();
        if (p->right) {
            if (p->right == s.top()) {
                s.pop();
                s.push(p);
                p = p->right;
            }
        } else {
            cout << p->data << " ";
            p = NULL;
        }
    } while(!s.empty());

}

void Tree::inOrderIterative(Node *p) {
    stack <Node *> s;
    while (p || s.empty()) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}

void Tree::levelOrder() {
    queue<Node *> q;
    Node *p = root;
    cout << p->data << " ";
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p->left) {
            cout << p->left->data << " ";
            q.push(p->left);
        }
        if (p->right) {
            cout << p->right->data << " ";
            q.push(p->right);
        }
    }
}

int main() {

    Tree t;
    t.createTree();
    cout << endl;
    t.levelOrder();
    cout << endl;
    return 0;
}