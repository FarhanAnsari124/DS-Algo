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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,nullptr});
        while(!q.empty()){
            int size=q.size();
            TreeNode* p_x=nullptr;
            TreeNode* p_y=nullptr;
            for(int i=0;i<size;i++){
                pair<TreeNode*,TreeNode*> curr=q.front();
                q.pop();
                if(curr.first->val==x){
                    p_x=curr.second;
                }
                if(curr.first->val==y){
                    p_y=curr.second;
                }
                if(curr.first->left)q.push({curr.first->left,curr.first});
                if(curr.first->right)q.push({curr.first->right,curr.first});
            }
            if(p_x!=nullptr && p_y!=nullptr && p_x!=p_y)return true;
        }
        return false;

        
    }
};