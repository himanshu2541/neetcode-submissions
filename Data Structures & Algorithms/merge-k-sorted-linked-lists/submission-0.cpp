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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // insert head of every node
        for(ListNode* node : lists){
            if (node != NULL){
                pq.push(node);
            }
        }

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();

            curr->next = smallest;
            curr = curr->next;

            // insert the next node from the same list
            if(smallest->next != NULL){
                pq.push(smallest->next);
            }
        }

        curr->next = NULL;

        return dummy->next;
    }
};
