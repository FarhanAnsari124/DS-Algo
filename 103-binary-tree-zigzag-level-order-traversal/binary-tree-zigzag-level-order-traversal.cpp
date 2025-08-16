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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root)return{};
        q.push(root);
        int size=q.size();
        bool l_to_r=true;
        while(!q.empty()){
            size=q.size();
            vector<int>v(size);
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                int ind=(l_to_r)?i:(size-i-1);
                v[ind]=temp->val;
            }
            l_to_r=!l_to_r;
            ans.push_back(v);
        }
        return ans;
    }
};