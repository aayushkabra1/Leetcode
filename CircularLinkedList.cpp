//
// Created by Aayush Kabra on 31-12-2021.
//
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head = new Node;

public:
    CircularLinkedList(){head = nullptr;}
    CircularLinkedList(const int A[], int size);
    ~CircularLinkedList();
    void display();
    int length();
    void insert(int element, int position);
};

CircularLinkedList::CircularLinkedList(const int A[], int size) {
    Node* last;
    head->data = A[0];
    head->next = nullptr;
    last = head;

    for (int i = 1; i < size; i++) {
        Node* t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
    last->next = head;
}

CircularLinkedList::~CircularLinkedList() {
    Node* t = head;
    Node* t1 = t->next;
    while(t1 != head) {
        delete t;
        t = t1;
        t1 = t1->next;
    }
    cout << "Heap Memory cleared" << endl;
}

void CircularLinkedList::display() {
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != head);
    cout << endl;
}

int CircularLinkedList::length() {
    Node* temp = head;
    int count = 0;
    do {
        count ++;
        temp = temp->next;
    }while (temp != head);
    return count;
}

void CircularLinkedList::insert(int element, int position) {
    Node* temp = new Node;
    if (position == 0) {
        if (head == nullptr) {
            temp->data = element;
            temp->next = temp;
            head = temp;
        } else {
            temp->data = element;
            temp->next = head;
            Node* p = head;
            while (p->next != head) p = p->next;
            p->next = temp;
        }
        head = temp;
    } else {
        Node* p = head;
        for (int i = 0; i < position - 1; i++) p = p->next;
        temp->data = element;
        temp->next = p->next;
        p->next = temp;
    }
}

int main() {

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CircularLinkedList l = CircularLinkedList(A, 10);
    l.display();
    cout << l.length() << endl;
    l.insert(11, 0);
    l.display();
    return 0;
}