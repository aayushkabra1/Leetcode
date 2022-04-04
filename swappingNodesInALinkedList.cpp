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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return nullptr;
        int n = 0;
        ListNode *temp = head, *tail;
        while(temp) {
            n++;
            tail = temp;
            temp = temp->next;
        }

        int first = k - 1, second = n - k;
        ListNode *firstNode = head, *secondNode = head;
        int i = 0;
        for(i; i < first; i++) {
            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }
        for (i; i < second; i++) {
            secondNode = secondNode->next;
        }
        swap(firstNode->val, secondNode->val);
        return head;
    }
};