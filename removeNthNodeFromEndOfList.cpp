#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *tail = head;
        ListNode *temp = head;
        while(temp) {
            size++;
            if (temp->next == nullptr) tail = temp;
            temp = temp->next;
        }

        if (head == tail) {
            delete(head);
            return nullptr;
        }

        temp = head;
        for (int i = 1; i < size - n; i++) {
            temp = temp->next;
        }
        ListNode *p = temp->next;
        temp->next = p->next;
        delete(p);
        return head;
    }
};