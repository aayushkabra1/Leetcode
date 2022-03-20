#include<iostream>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = new ListNode(-101);
        prev->next = head;
        ListNode *curr = prev;

        while(curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val){
                ListNode *temp = curr->next->next;
                while(temp && curr->next->val == temp->val) {
                    ListNode *del = temp;
                    temp = temp->next;
                    delete(del);   
                }
                curr->next = temp;
            } else {
                curr = curr->next;
            }
        }
        return prev->next;
    }
};