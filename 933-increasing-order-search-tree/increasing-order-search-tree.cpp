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
    void solve(TreeNode* root,TreeNode* &prev){
        if(!root)return;
        solve(root->left,prev);
        prev->right=root;
        prev=root;
        root->left=nullptr;
        solve(root->right,prev);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy=new TreeNode(-1);
        TreeNode* prev=dummy;
        solve(root,prev);
        return dummy->right; 
    }
};