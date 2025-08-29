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
    void solve(TreeNode* root){
        if(root==nullptr)return;
        if(root->left && root->right){
            swap(root->left,root->right);
        }else{
            swap(root->left,root->right);
        }
        if(root->left)solve(root->left);
        if(root->right)solve(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};