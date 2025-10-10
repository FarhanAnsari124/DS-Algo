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
struct info{
    int sum;
    int min;
    int max;
    bool isbst;
}; 
class Solution {
public:
    int maxsum=0;
    info solve(TreeNode* root){
        if(root==nullptr){
            return {0,(int)1e5,(int)-1e5,1};//{sum,min,max,isbst}
        }
        info left=solve(root->left);
        info right=solve(root->right);
        bool l=left.isbst;
        bool r=right.isbst;
        if(r && l && root->val>left.max && root->val<right.min){
            int sum=left.sum+right.sum+root->val;
            maxsum=max(sum,maxsum);
            int mini=min({left.min,root->val});
            int maxi=max({right.max,root->val});
            return {sum,mini,maxi,1};
        }else{
            return {0,0,0,0};
        }
    }
    int maxSumBST(TreeNode* root) {
        info temp=solve(root);
        return maxsum;
    }
};