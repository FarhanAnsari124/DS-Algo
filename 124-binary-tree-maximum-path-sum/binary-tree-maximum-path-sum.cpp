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
    int maxsum=-1e9;
    int solve(TreeNode* root){
        if(!root)return 0;
        int left=solve(root->left)+root->val;
        int right=solve(root->right)+root->val;
        maxsum=max({left,right,left+right-root->val,maxsum,root->val});
        return max({left,right,root->val});
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};