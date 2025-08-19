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
    bool solve(TreeNode* p,TreeNode* q){
        if(p==nullptr && q==nullptr)return true;
        if((p==nullptr && q!=nullptr) || (p!=nullptr && q==nullptr))return false;
        if(p->val != q->val)return false;
        bool left=solve(p->left,q->right);
        bool right=solve(p->right,q->left);
        return left && right;
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};