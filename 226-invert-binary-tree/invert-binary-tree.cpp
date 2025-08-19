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
        }
        else if(root->left){
            root->right=root->left;
            root->left = nullptr;
        }
        else if(root->right){
            root->left=root->right;
            root->right = nullptr;
        }
        solve(root->left);
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        solve(root);
        return root;

    }
};