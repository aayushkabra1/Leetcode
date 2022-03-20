//
// Created by Aayush Kabra on 01-01-2022.
//
#include<iostream>
using namespace std;

class StackFromArray{
private :
    int size;
    int top;
    int* arr;

public:
    explicit StackFromArray(int size);
    ~StackFromArray();
    void push(int data);
    int pop();
    int getSize() const;
    void display() const;
    int peek(int position) const;
    bool isEmpty() const;
    bool isFull() const;
};

StackFromArray::StackFromArray(int size) {
    this->size = size;
    this->top = -1;
    this->arr = new int[size];
}

StackFromArray::~StackFromArray() {
    delete[] arr;
    cout << endl << "Destructor called" << endl;
}

void StackFromArray::push(int data) {
    if (top == size - 1) {
        cout << "Stack is full, can't push " << data << endl;
        return;
    } else {
        top++;
        arr[top] = data;
    }
}

int StackFromArray::getSize() const {
    return size;
}

void StackFromArray::display() const {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
}

int StackFromArray::pop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    } else {
        top--;
        return arr[top+1];
    }
    cout << endl;
}

int StackFromArray::peek(int position) const {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    } else {
        return arr[top - position - 1];
    }
}

bool StackFromArray::isEmpty() const {
    return top == -1;
}

bool StackFromArray::isFull() const {
    return top == size - 1;
}

int main() {
    StackFromArray s(5);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.display();
    s.push(7);
    cout << "Size of stack is " << s.getSize() << endl;
    cout << s.pop() << endl;
    s.display();
    return 0;
}
