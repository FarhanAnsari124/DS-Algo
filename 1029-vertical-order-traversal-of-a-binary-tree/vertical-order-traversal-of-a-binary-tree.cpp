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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr)return ans;
        map<int,map<int,multiset<int>>>mapy;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            TreeNode* node=tp.first;
            int x=tp.second.first,y=tp.second.second;
            if(node!=nullptr)mapy[x][y].insert(node->val);
            if(node->left)q.push({node->left,{x-1,y+1}});
            if(node->right)q.push({node->right,{x+1,y+1}});
        }
        for(auto x:mapy){
            vector<int>temp;
            for(auto y:x.second){
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};