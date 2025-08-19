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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        if(root==NULL)return ans;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            vector<int>v;
            if(!s1.empty()){
                while(!s1.empty()){
                    TreeNode* temp=s1.top();s1.pop();
                    if(temp->left)s2.push(temp->left);
                    if(temp->right)s2.push(temp->right);
                    v.push_back(temp->val);
                }
            }else{
                while(!s2.empty()){
                    TreeNode* temp=s2.top();s2.pop();
                    if(temp->right)s1.push(temp->right);
                    if(temp->left)s1.push(temp->left);
                    v.push_back(temp->val);
                }

            }
            ans.push_back(v);
        }
        return ans;
        
    }
};