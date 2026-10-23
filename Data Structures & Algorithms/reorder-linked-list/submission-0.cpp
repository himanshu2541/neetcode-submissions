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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // Find the length
        int length = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Find the start of the second half
        int mid = (length + 1) / 2;

        ListNode* list2 = head;
        for (int i = 0; i < mid; i++) {
            list2 = list2->next;
        }

        // Split the first half from the second half
        ListNode* list1 = head;
        temp = head;

        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        temp->next = nullptr;

        // Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = list2;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        list2 = prev;

        // Merge alternately
        while (list1 != nullptr && list2 != nullptr) {
            ListNode* next1 = list1->next;
            ListNode* next2 = list2->next;

            list1->next = list2;
            list2->next = next1;

            list1 = next1;
            list2 = next2;
        }
    }
};
