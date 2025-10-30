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
    int solve(TreeNode* root){
        if(!root->left && !root->right)return 1;
        int left=1e9;
        int right=1e9;
        if(root->left)left=minDepth(root->left);
        if(root->right)right=minDepth(root->right);
        return 1+min(left,right);
    }
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int d=q.front().second;
            q.pop();
            if(!node->left && !node->right)return d+1;
            if(node->left)q.push({node->left,d+1});
            if(node->right)q.push({node->right,d+1});
        }
        return 0;
    }
};