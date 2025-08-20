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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        queue<pair<TreeNode*,int>>q;
        map<int,int>mapy;
        q.push({root,0});
        while(!q.empty()){
            auto np=q.front();
            TreeNode* node=np.first;
            int x=np.second;
            mapy[x]=node->val;
            if(node->left)q.push({node->left,x+1});
            if(node->right)q.push({node->right,x+1});
            q.pop();
        }
        vector<int>ans;
        for(auto x:mapy){
            ans.push_back(x.second);
        }
        return ans;
    }
};