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
    void solve(TreeNode* root,vector<int>&inord){
        if(root==nullptr){
            return;
        }
        solve(root->left,inord);
        inord.push_back(root->val);
        solve(root->right,inord);
    }
    void rec(TreeNode* root,vector<int>&inord,int &i){
         if(root==nullptr){
            return;
        }
        rec(root->left,inord,i);
            root->val=inord[i++];
        rec(root->right,inord,i);
    }
    void recoverTree(TreeNode* root) {
        vector<int>inord;
        solve(root,inord);
        sort(inord.begin(),inord.end());
        int i=0;
        rec(root,inord,i);
    }
};