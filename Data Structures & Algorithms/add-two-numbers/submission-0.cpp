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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        int carry = 0;
        while(temp1 != NULL || temp2 != NULL || carry){
            int sum = carry;

            if(temp1!=NULL){
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if(temp2 != NULL){
                sum += temp2->val;
                temp2 = temp2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            ListNode *newNode = new ListNode(digit);
            curr->next = newNode;
            curr = curr->next;
        }

        return dummy->next;
    }
};
