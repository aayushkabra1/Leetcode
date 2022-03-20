#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BST2 {
    public:
    Node *root;
    BST2() {root = nullptr;}

    Node * search(Node *p, int key);
    Node * search(int key) {return search(root, key);}

    void insert(int key);
    
    void in_order() {in_order(root);}
    void in_order(Node *p);

    Node * next(Node *p);
    Node * left_descendant(Node *p);
    Node * right_ancestor(Node *p);

    vector<Node *> range_search(int x, int y);
    
    void remove(Node *root, int key);
};

Node * BST2::search(Node *p, int key) {
    if (p == nullptr) return nullptr;
    if (p->data == key) return p;
    else if (p->data > key) {
        if (p->left) return search(p->left, key);
        return p;
    } else {
        if (p->right) return search(p->right, key);
        return p;
    }
}

void BST2::insert(int key) {
    if (root == nullptr) root = new Node(key);
    else {
        Node *p = search(key);
        if (p->data == key) return;
        else if (p->data > key) {
            Node *t = new Node(key);
            p->left = t;
        } else {
            Node *t = new Node(key);
            p->right = t;
        }
    }
}

void BST2::in_order(Node *p) {
    if (!p) return;
    in_order(p->left);
    cout << p->data << " ";
    in_order(p->right);
}

Node * BST2::next(Node *p) {
    if (p == root) return p;
    if (p->right) return left_descendant(p->right);
    else return right_ancestor(p);
}

Node * BST2::left_descendant(Node *p) {
    while (p->left) {
        p = p->left;
    }
    return p;
}

Node * BST2::right_ancestor(Node *p) {
    if (p == root) return p;
    vector<Node *> ancestors;
    Node *q = root;
    while(q != p) {
        ancestors.push_back(q);
        if (q->data > p->data) {
            q = q->left;
        } else if (q->data < p->data) {
            q = q->right;
        }
    }
    for(int i = ancestors.size() - 1; i >= 0; i--) {
        if (ancestors[i]->data > p->data) return p;
    }
}

vector<Node *> BST2::range_search(int x, int y) {
    vector<Node *> nodes;
    Node *p = search(x);
    while(p->data <= y) {
        if (p->data > x) {
            nodes.push_back(p);
        }
        p = next(p);
    }
    return nodes;
}

int main(int argc, char const *argv[])
{
    BST2 bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);

    bst.in_order();
    
    return 0;
}
