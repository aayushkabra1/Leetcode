//
// Created by Aayush Kabra on 31-12-2021.
//

#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int data;
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {head = nullptr;}
    DoublyLinkedList(const int A[], int size);
    ~DoublyLinkedList();
    void display();
    void insert(int data, int position);
    void reverse();
};

DoublyLinkedList::DoublyLinkedList(const int A[], int size) {
    head = new Node;
    head->data = A[0];
    head->prev = nullptr;
    head->next = nullptr;
    Node* last = head;
    Node* t;

    for (int i = 1; i < size; i++) {
        t = new Node;
        last->next = t;
        t->data = A[i];
        t->prev = last;
        last = t;
    }
    last->next = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* p = head;
    while(p != nullptr) {
        Node* q = p->next;
        delete p;
        p = q;
    }
    cout << "Memory Cleared" << endl;
}

void DoublyLinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DoublyLinkedList::insert(int data, int position) {
    Node* t = new Node;
    if (position == 0) {
        t->prev = nullptr;
        t->next = head;
        head->prev = t;
        head = t;
    } else {
        Node* p = head;
        for (int i = 0; i < position - 1; i++) {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (t->next) t->next->prev = t;
        p->next = t;
    }
}

void DoublyLinkedList::reverse() {
    Node* p = head;
    while(p) {
        if (p->next == nullptr) {
            head = p;
        }
        Node* t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    DoublyLinkedList dll(A, 5);
    dll.display();
    dll.reverse();
    dll.display();
    return 0;
}
