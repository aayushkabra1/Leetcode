//
// Created by Aayush Kabra on 28-12-2021.
//
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* first;
    LinkedList() {first = nullptr;}
    LinkedList(const int A[], int n);
    ~LinkedList();

    void display() const;
    void insertAt(int data, int index);
    void remove(int element);
    int length() const;
    void reverse();
};

LinkedList::LinkedList(const int A[], int n) {
    Node* last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last= first;

    for (int i = 1; i < n; i++) {
        Node* t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void LinkedList::display() const {
    Node* t = first;
    while (t->next != nullptr) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

void LinkedList::insertAt(int data, int index) {
    if (index == 0) {
        Node* t = new Node;
        t->data = data;
        t->next = first;
        first = t;
    }
    else {
        Node* p = first;
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        Node* t = new Node;
        t->data = data;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::length() const {
    int len = 0;
    Node* p = first;
    while(p->next != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::remove(int element) {
    if (first->data == element) {
        Node* p = first;
        first = first->next;
        delete p;
    } else {
        Node* p = first;
        Node* q = first;
        while(p && p->data != element) {
            q = p;
            p = p->next;
        }
        if (p) {
            q->next = p->next;
            delete p;
        }
    }
}

void LinkedList::reverse() {
    Node* p = first;
    Node* q = nullptr;
    Node* r = nullptr;

    while (p != nullptr) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main() {
    int A[] = {3, 5, 7, 10};
    LinkedList l = LinkedList(A, 5);
//    l.display();
    l.insertAt(9, 3);
//    l.display();
//    cout << "Length = " << l.length() << endl;
    l.remove(10);
    l.display();
//    cout << "Length = " << l.length() << endl;

    cout << "Reversing" << endl;
    l.reverse();
    cout << "List after reversing = ";
    l.display();

    // Clearing heap memory
    Node* t = l.first;
    while (t->next != nullptr) {
        Node* temp = t;
        t = t->next;
        delete temp;
    }
    cout << "Memory cleared" << endl;
    return 0;
}