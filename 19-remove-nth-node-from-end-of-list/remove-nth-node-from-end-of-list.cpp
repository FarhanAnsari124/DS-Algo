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
        ListNode* pre;
        ListNode* temp=head;
        pre=head;
        int cnt=0;
        while(temp!=nullptr){
            if(cnt>n){
                pre=pre->next;
            }
            temp=temp->next;
            cnt++;
        }
        if(cnt==1){
            return nullptr;
        }else if(cnt==n){
            return head->next;
        }
        ListNode* tbd = pre->next;
        pre->next = tbd->next;
        tbd->next = nullptr;
        return head;

    }
};