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
    map<TreeNode*,TreeNode*>mapy;
    void solve(TreeNode* root,TreeNode* parent){
        if(!root)return;
        if(root->left){
            mapy[root->left]=root;
            solve(root->left,root);
        }
        if(root->right){
            mapy[root->right]=root;
            solve(root->right,root);
        }
    }
    vector<int>ans;
    void takekthelements(TreeNode* target,int k,set<TreeNode*>&visited){
        if(target==nullptr)return;
        if(visited.find(target)!=visited.end())return;
        else visited.insert(target);
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        takekthelements(target->left,k-1,visited);
        takekthelements(target->right,k-1,visited);
        if(mapy[target])takekthelements(mapy[target],k-1,visited);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       solve(root,nullptr);
        set<TreeNode*>visited;
       takekthelements(target,k,visited);
        return ans;

    }
};