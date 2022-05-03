#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = -1;
        next = nullptr;
    }

    Node(int data_) {
        data = data_;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node *head;
    Node *tail;
    int length;
    MyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        length = 0;
    }
    
    int get(int index) {
        if (index >= length) return -1;
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node *newHead = new Node(val);
        if (!head && !tail) {
            this->head = newHead;
            this->tail = newHead;
        }
        else {
            newHead->next = head;
            head = newHead;
        }
        length++;
    }
    
    void addAtTail(int val) {
        Node *newTail = new Node(val);
        if (!head && !tail) {
            this->head = newTail;
            this->tail = newTail;
        }
        else {
            this->tail->next = newTail;
            tail = newTail;
        }
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > this->length) return;
        if (index == 0) {
            this->addAtHead(val);
            return;
        }
        if (index == length) {
            this->addAtTail(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= this->length) return;
        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete(temp);
        }
        else if (index == length - 1) {
            Node *temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
            delete(tail);
            tail = temp;
        }
        else {
            Node *temp = head;
            Node *prev = nullptr;
            for (int i = 0; i < index; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete(temp);
        }
        this->length--;
    }
};