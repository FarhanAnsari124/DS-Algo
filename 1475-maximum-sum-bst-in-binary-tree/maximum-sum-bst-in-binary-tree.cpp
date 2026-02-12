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
    vector<int> solve(TreeNode* root){
        if(!root)return {0,INT_MIN,INT_MAX,0};//{sum,max,min,maxsum};
        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        if(left[1]<root->val && root->val<right[2]){
            int sum=left[0]+right[0]+root->val;
            return {sum,max(root->val,right[1]),min(root->val,left[2]),max({left[3],right[3],sum})};
        }else{
            return {0,INT_MAX,INT_MIN,max(left[3],right[3])};
        }
    }
    int maxSumBST(TreeNode* root) {
        vector<int> ans=solve(root);
        // cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<;
        return ans[3];
    }
};