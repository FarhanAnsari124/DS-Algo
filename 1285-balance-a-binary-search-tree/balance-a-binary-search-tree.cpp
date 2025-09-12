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
    vector<int>nodes;
    void inorder(TreeNode* root){
        if(root==nullptr)return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* make_tree(int low,int high,vector<int>&nodes){
        if(low>high){
            return nullptr;
        }
        int mid=(low+high)/2;
        TreeNode* root=new TreeNode(nodes[mid]);
        root->left=make_tree(low,mid-1,nodes);
        root->right=make_tree(mid+1,high,nodes);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inorder(root);
        return make_tree(0,nodes.size()-1,nodes);
    }
};