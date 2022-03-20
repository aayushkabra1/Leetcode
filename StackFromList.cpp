//
// Created by Aayush Kabra on 01-01-2022.
//

#include<iostream>
#include<list>
using namespace std;

class StackFromList{
private:
    int size;
    int top;
    list<int> l;

public:
    StackFromList(int A[], int size);
    explicit StackFromList(int size);
    ~StackFromList();
    void print();
    void push(int x);
    int pop();
    bool isEmpty();
    bool isFull() const;
};

StackFromList::StackFromList(int A[], int size) {
    this->size = size;
    this->top = -1;
    for (int i = 0; i < size; i++) {
        l.push_front(A[i]);
    }
}

StackFromList::StackFromList(int size) {
    this->size = size;
    this->top = size - 1;
    this->l = list<int>(size);
}

StackFromList::~StackFromList() {
    l.clear();
}

void StackFromList::print() {
    for (auto i : l) {
        cout << i << " ";
    }
    cout << endl;
}

void StackFromList::push(int x) {
    if (top == size - 1) {
        cout << "Stack is full" << endl;
        return;
    }
    top++;
    l.push_front(x);
}

int StackFromList::pop() {
    if (top == -1) {
        cout << "Empty Stack" << endl;
        return -1;
    }
    top--;
    l.pop_front();
    return l.front();
}

bool StackFromList::isEmpty() {
    return l.empty();
}

bool StackFromList::isFull() const {
    return size == top + 1;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    StackFromList s(A, 5);
    s.print();
    s.push(6);
    s.print();
    s.pop();
    s.print();
    return 0;
}