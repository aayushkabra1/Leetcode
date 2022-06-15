#include <iostream>
#include "TreeNode.cpp"
#include "ListNode.cpp"
using namespace std;

int _ = [] () {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    return 0;
} ();

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        int length = 0;
        ListNode *temp = head;
        while(temp) {
            length++;
            temp = temp->next;
        }
        
        if (length == 1) return new TreeNode(head->val);
        
        ListNode *mid = head, *prev = nullptr;
        for (int i = 0; i < length / 2; i++) {
            prev = mid;
            mid = mid->next;
        }
        
        prev->next = nullptr;
        ListNode *nextHead = mid->next;
        mid->next = nullptr;

        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(nextHead);

        return root;
    }
};
