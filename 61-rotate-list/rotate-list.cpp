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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)return head;
        int size=0;
        ListNode* temp=head;
        ListNode* last;
        while(temp!=nullptr){
            last=temp;
            temp=temp->next;
            size++;
        }
        last->next=head;
        int c=0;
        int d=size-(k%size)-1;
        temp=head;
        while(d--){
            temp=temp->next;
        }
        ListNode* ans=temp->next;
        temp->next=nullptr;
        return ans;

    }
};