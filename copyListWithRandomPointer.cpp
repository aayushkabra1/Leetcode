#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;

        Node *tmp = head;
        while(tmp != nullptr) {
            Node *copy = new Node(tmp->val);
            Node *next = tmp->next;
            tmp->next = copy;
            copy->next = next;
            tmp = next;
        }

        Node *old = head;
        while(old != nullptr && old->next != nullptr) {
            old->next->random = old->random == nullptr ? nullptr : old->random->next;
            old = old->next->next;
        }

        Node *newHead = new Node(-1);
        old = head;
        Node* copy = newHead;
        while(old != nullptr && old->next != nullptr) {
            Node *nextOld = old->next->next;
            copy->next = old->next;
            old->next = nextOld;
            old = old->next;
            copy = copy->next;
        }
        
        return newHead->next;
    }
};