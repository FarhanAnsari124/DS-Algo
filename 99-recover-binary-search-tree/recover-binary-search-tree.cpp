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
    void solve(TreeNode* root,vector<int>&inord,bool &making,int &i){
        if(root==nullptr){
            return;
        }
        solve(root->left,inord,making,i);
        if(making)inord.push_back(root->val);
        else {
            root->val=inord[i++];
        }
        solve(root->right,inord,making,i);
    }
    void recoverTree(TreeNode* root) {
        vector<int>inord;
        int i=0;
        bool making=true;
        solve(root,inord,making,i);
        sort(inord.begin(),inord.end());
        making=false;
        solve(root,inord,making,i);
    }
};