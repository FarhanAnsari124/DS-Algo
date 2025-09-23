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
    bool getPath(TreeNode* root,vector<TreeNode*>&p1,TreeNode* target){
        if(root==nullptr){
            return false;
        }
        p1.push_back(root);
        if(root->val==target->val){
            return true;
        }
        if(getPath(root->left,p1,target)||getPath(root->right,p1,target)){
            return true;
        }
        p1.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p1;
        getPath(root,p1,p);
        vector<TreeNode*>p2;
        getPath(root,p2,q);
        TreeNode* ans;
        for(int i=0;i<min(p1.size(),p2.size());i++){
            if(p1[i]->val==p2[i]->val){
                ans=p1[i];
            }
        }
        return ans;

    }
};