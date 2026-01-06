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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ind=1;
        int i=1;
        int maxi=root->val;
        while(!q.empty()){
            int s=q.size();
            int sum=0;
            for(int i=0;i<s;i++){
                auto top=q.front();
                q.pop();
                sum+=top->val;
                if(top->right)q.push(top->right);
                if(top->left)q.push(top->left);
            }
            if(sum>maxi){
                maxi=sum;
                ind=i;
            }
            i++;
        }
        return ind;
    }
};