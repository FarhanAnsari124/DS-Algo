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
    int maxsum=0;
    vector<int>solve(TreeNode* root){
        if(root==nullptr){
            return {0,(int)1e5,(int)-1e5,1};//{sum,min,max,isbst}
        }
        vector<int>left=solve(root->left);
        vector<int>right=solve(root->right);
        bool l=left[3];
        bool r=right[3];
        if(r && l && root->val>left[2] && root->val<right[1]){
            int sum=left[0]+right[0]+root->val;
            maxsum=max(sum,maxsum);
            int mini=min({left[1],root->val});
            int maxi=max({right[2],root->val});
            return {sum,mini,maxi,1};
        }else{
            return {0,0,0,0};
        }
    }
    int maxSumBST(TreeNode* root) {
        vector<int>temp=solve(root);
        return maxsum;
    }
};