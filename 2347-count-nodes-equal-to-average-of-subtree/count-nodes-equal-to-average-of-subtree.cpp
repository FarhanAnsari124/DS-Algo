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
    int cnt=0;
    pair<int,int> solve(TreeNode* root){
        if(root==nullptr)return {0,0};
        auto left=solve(root->left);
        auto right=solve(root->right);
        int count=1+left.first+right.first;
        int sum=root->val+left.second+right.second;
        if(sum/count==root->val)cnt++;
        return {count,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return cnt;
    }
};