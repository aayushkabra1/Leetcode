#include <iostream>
#include "listNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *first = head->next, *second = head->next->next;

        first->next = head;
        head->next = swapPairs(second);
        return first;
    }
};