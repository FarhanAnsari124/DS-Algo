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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return nullptr;
        if(!head->next) return new TreeNode(head->val);

        ListNode *prev=nullptr,*slow=head,*fast=head;
        //finding middle element
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //discnt left half
        if(prev)prev->next=nullptr;
        //slow is mid->root
        TreeNode * root=new TreeNode(slow->val);
        //left half->left subtree
        if(slow!=head){
            root->left=sortedListToBST(head);
        }
        //right half->right subtree
        root->right=sortedListToBST(slow->next);
        return root;

    }
};