#include <iostream>
#include <vector>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode *tail = head;
        int len = 1;
        while(tail->next) {
            tail = tail->next;
            len++;
        }
        tail->next = head;

        k = k % len;
        int count = len - k;
        while (count--) {
            head = head->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        return head;
    }
};