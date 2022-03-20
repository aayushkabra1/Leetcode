#include <iostream>
using std::cout;
using std::endl;

class AVLNode {
    public:

    int data, height;
    AVLNode *left, *right, *parent;

    AVLNode(int data) {
        this->data = data;
        left = right = parent = nullptr;
    }
};

class AVLTree{
    public:

    AVLNode* root;
    AVLTree() {this->root = nullptr;}
    int height(AVLNode *p);
    int bf(AVLNode *p);

    AVLNode * ll_rot(AVLNode *p);
    AVLNode * rr_rot(AVLNode *p);
    AVLNode * lr_rot(AVLNode *p);
    AVLNode * rl_rot(AVLNode *p);

    AVLNode * insert(int key) {return insert(root, key);}
    AVLNode * insert(AVLNode *p, int key);

    AVLNode * delete_node(AVLNode *p, int key);
    AVLNode * delete_node(int key) {return delete_node(root, key);}

    AVLNode * parent(AVLNode *p);
};

int AVLTree::height(AVLNode *p) {
    if (p == nullptr) return -1;
    int rheight = height(p->right);
    int lheight = height(p->left);
    return 1 + std::max(lheight, rheight);
}

int AVLTree::bf(AVLNode *p) {
    if (p->left && p->right) return height(p->left) - height(p->right);
    if (p->left && p->right == nullptr) return height(p->left);
    if (p->left == nullptr && p->right) return -height(p->right);
}

AVLNode * AVLTree::ll_rot(AVLNode *p) {
    AVLNode *current = p;
    AVLNode *left_node = p->left;

    current->left = left_node->left;
    left_node->right = current;

    return left_node;
}

AVLNode * AVLTree::rr_rot(AVLNode *p) {
    AVLNode *current = p;
    AVLNode *right_node = p->right;

    current->right = right_node->left;
    right_node->left = current;

    return right_node;
}

AVLNode * AVLTree::rl_rot(AVLNode *p) {
    AVLNode *current = p;
    AVLNode *r = p->right;
    AVLNode *rl = p->right->left;

    current->right = rl->left;
    r->left = rl->right;
    rl->left = current;
    rl->right = r;

    return rl;
}

AVLNode * AVLTree::lr_rot(AVLNode *p) {
    AVLNode *current = p;
    AVLNode *l = p->left;
    AVLNode *lr = p->left->right;

    current->left = lr->right;
    l->right = lr->left;
    lr->left = l;
    lr->right = current;

    return lr;
}

AVLNode * AVLTree::insert(AVLNode *p, int key) {
    if (p == nullptr) {
        p = new AVLNode(key);
    } else {
        if (p->data > key) p->left = insert(p->left, key);
        else p->right = insert(p->right, key);
    }
    p->height = height(p);

    // Balance the tree
    if (bf(p) == 2 && bf(p->left) == 1) p == ll_rot(p);
    else if (bf(p) == -2 && bf(p->right) == -1) p = rr_rot(p);
    else if (bf(p) == -2 && bf(p->right) == 1) p = rl_rot(p);
    else if (bf(p) == 2 && bf(p->left) == -1) p = lr_rot(p);

    return p;
}

AVLNode * AVLTree::delete_node(AVLNode *p, int key) {

    if (p->left == nullptr && p->right == nullptr) {
        AVLNode *q = this->parent(p);
        if (q->left == p)
            q->left = nullptr;
        if (q->right == p)
            q->right = nullptr;
        delete p;
        p = nullptr;
        return p;
    }

    if (p->data > key) p->left = delete_node(p->left, key);
    else if (p->data < key) p->right = delete_node(p->right, key);
    else {

    }
}

AVLNode * AVLTree::parent(AVLNode *p) {
    if (p == root) return p;
    AVLNode *q = root;
    while(q->right != p && q->left != p) {
        if (q->data > p->data) q = q->left;
        else if (q->data < p->data) q = q->right;
    }
    return q;
}

int main(int argc, char const *argv[]) {
  
  return 0;
}
