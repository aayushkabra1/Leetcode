#include<iostream>
using std::cout;
using std::endl;

class Node {
public:
  Node *left;
  int data;
  Node *right;
};

class BST{
    void inOrder(Node *p);
    Node* rInsert(Node *p, int data);

    public:
    Node *root;

    BST() {root = NULL;}
    Node* search(int data);
    Node* remove(int key) {return remove(key, root);}
    Node* remove(int key, Node *root);
    void insert(int data);
    Node* rInsert(int data){rInsert(root, data);}
    void inOrder(){inOrder(root);}
    Node* in_order_successor(Node *p);
    Node* in_order_predecessor(Node *p);

    int height() {return height(root);}
    int height(Node *p);
};

Node* BST::search(int data) {
    Node *p = root;
    while(p != nullptr) {
        if (p->data == data) {
            return p;
        } else if (p->data > data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return nullptr;
}

void BST::insert(int data) {

    if (root == nullptr) {
        Node *t = new Node;
        root = t;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }

    Node *p = root;
    Node *q = nullptr;
    while (p != nullptr) {
        q = p;
        if (p->data == data) return;
        if (p->data > data) p = p->left;
        else p = p->right;
    }

    Node *t = new Node;
    t->data = data;
    t->left = nullptr;
    t->right = nullptr;
    if (q->data > data) q->left = t;
    else  q->right = t;
}

Node* BST::remove(int key, Node *root) {
    if (root == nullptr) return nullptr;
    else if (key < root->data) root->left = remove(key, root->left);
    else if (key > root->data) root->right = remove(key, root->right);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            Node *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node *temp = root;
            root = root->left;
            delete temp;
        } else {
            Node *temp = in_order_successor(root);
            root->data = temp->data;
            root->right = remove(key, root->right);
        }
        return root;
    }
}

void BST::inOrder(Node *p) {
    if (!p) return;
    inOrder(p->left);
    cout << p->data << " ";
    inOrder(p->right);
}

Node* BST::rInsert(Node* p, int data) {
    Node *t = nullptr;
    if (p == nullptr) {
        t = new Node;
        t->data = data;
        t->left = nullptr;
        t->right = nullptr;
    }

    if (p->data > data) {
        p->left = rInsert(p->left, data);
    } else if (p->data < data) {
        p->right = rInsert(p->right, data);
    }
    return p;
}

Node* BST::in_order_successor(Node *p) {
    Node *temp = p;
    temp = temp->right;
    while(temp->left) temp = temp->left;
    return temp;
}

Node* BST::in_order_predecessor(Node *p) {
    Node *temp = p;
    temp = temp->left;
    while(temp->right) temp = temp->right;
    return temp;
}

int BST::height(Node *p) {
    if (p == nullptr) return -1;
    int left_height = height(p->left);
    int right_height = height(p->right);
    return 1 + std::max(left_height, right_height);
}

int main() {
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.inOrder();
    cout << endl;
    cout << bst.search(10) << endl;
    cout << bst.search(20) << endl;
    cout << bst.height() << endl;
    bst.remove(5);
    bst.inOrder();
    return 0;
}