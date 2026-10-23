/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Find length
        int len = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // Node to remove is the head
        if (len == n) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Find the node to remove
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < len - n; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};
