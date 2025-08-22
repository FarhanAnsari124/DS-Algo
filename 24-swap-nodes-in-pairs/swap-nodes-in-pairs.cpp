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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,nullptr);
        dummy.next=head;
        ListNode* prev=&dummy;
        while(prev->next && prev->next->next){
            ListNode* first=prev->next;
            ListNode* second=first->next;
            prev->next=second;//stored for next iteration
            first->next=second->next;//swapping
            second->next=first;//swapping
            prev=first;//nya prev first ko bna diya h jo ki next iteration me dono swapping nodes se phle hoga to hmlog swap krrke prev k second ko chnge kr pynge
        }
        return dummy.next;
    }
};