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
        return solve(root);
    }
};