//
// Created by Aayush Kabra on 03-01-2022.
//

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Queue{
private:
    Node *front, *rear;

public:
    Queue();
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    bool isFull();
};

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int data) {
    Node *t = new Node;
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }
    if (isEmpty()) {
        front = t;
        rear = t;
    } else {
        rear->next = t;
        rear = t;
    }
    t->data = data;
    t->next = nullptr;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        Node *p = front;
        int data = p->data;
        front = front->next;
        delete p;
        return data;
    }
}

bool Queue::isFull() {
    Node *t = new Node;
    if (t) {
        return false;
    } else {
        return true;
    }
}

bool Queue::isEmpty() {
    return front == nullptr;
}