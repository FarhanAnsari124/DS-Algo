/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return false;
        }
        bool l=dfs(root->left,p,q);
        bool r=dfs(root->right,p,q);

        bool mid=(root==p || root==q);

        if((mid?1:0)+(l?1:0)+(r?1:0)>=2){
            ans=root;
        }
        return l||r||mid;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};