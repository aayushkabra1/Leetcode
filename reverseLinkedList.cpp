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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = nullptr, *q = head, *r = nullptr;
        while(q) {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head = p;
        return head;
    }
};