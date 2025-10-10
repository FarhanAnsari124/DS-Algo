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
    vector<long long>ans;
    pair<bool,int> solve(TreeNode* root){
        if(!root)return {true,-1};
        auto left=solve(root->left);
        auto right=solve(root->right);
        if(left.first && right.first && left.second==right.second){
            long long nodes = (1LL << (left.second + 2)) - 1;
            ans.push_back(nodes);
            return {true,left.second+1};
        }else return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        auto an=solve(root);
        sort(ans.rbegin(),ans.rend());
        if(k>ans.size())return -1;
        return ans[k-1];
        
    }
};