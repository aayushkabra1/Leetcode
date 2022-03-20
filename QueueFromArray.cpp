//
// Created by Aayush Kabra on 03-01-2022.
//
#include<iostream>
using namespace std;

class Queue{
private:
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue() {front = rear = -1; size = 10; arr = new int[size];}
    explicit Queue(int size) {front = rear = -1; this->size = size; arr = new int[size];}
    void enqueue(int data);
    int dequeue();
    void display();
    bool isEmpty() const;
    bool isFull() const;
};

void Queue::enqueue(int data) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else {
        rear = (rear + 1) / size;
        arr[rear] = data;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        front = (front + 1) / size;
        return arr[front];
    }
}

void Queue::display() {
    for (int i = front + 1; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool Queue::isEmpty() const {
    return front == rear;
}

bool Queue::isFull() const {
    return (rear + 1) % size == front;
}

int main() {

    return 0;
}
