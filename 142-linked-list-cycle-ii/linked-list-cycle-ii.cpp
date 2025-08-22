/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while(head){
            if(head->val==INT_MIN)break;
            head->val=INT_MIN;
            head=head->next;
        }
        return head;
    }
};