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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while(true){
            // find the kth node of current group
            ListNode *kth = groupPrev;

            for(int i = 0; i < k && kth != NULL; i++){
                kth = kth->next;
            }

            // not enough nodes remaining
            if(kth == NULL) break;

            ListNode* groupNext = kth->next;

            // reverse the current group
            ListNode *prev = groupNext;
            ListNode *curr = groupPrev->next;

            while(curr != groupNext){
                ListNode* next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // reconnect the reversed group
            ListNode *oldGroupHead = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = oldGroupHead;
        }

        return dummy->next;
    }   
};














