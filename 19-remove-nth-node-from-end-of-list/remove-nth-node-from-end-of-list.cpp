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
        ListNode* temp=head;
        if(head->next==nullptr)return nullptr;
        int sz=0;
        while(temp!=nullptr){
            temp= temp->next;
            sz++;
        }
        int tobeRemoved = sz-n;
        if(tobeRemoved==0){
            head=head->next;
            return head;
        }
        temp=head;
        ListNode* prev=nullptr;
        while(tobeRemoved--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=nullptr;
        return head;
    }
};