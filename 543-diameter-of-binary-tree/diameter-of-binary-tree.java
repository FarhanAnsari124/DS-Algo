/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int maxi=-1;
    int dfs(TreeNode root){
        if(root==null)return 0;
        int left=0;
        int right=0;
        if(root.left!=null){
            left=dfs(root.left);
        }
        if(root.right!=null){
            right=dfs(root.right);
        }
        int dia=left+right;
        if(dia>maxi){
            maxi=dia;
        }
        if(left>right){
            return 1+left;
        }else return 1+right;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int dummy=dfs(root);
        return maxi;
    }
}