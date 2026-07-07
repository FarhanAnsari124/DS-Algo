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
class Pair {
    TreeNode curr;
    TreeNode parent;
    Pair(TreeNode curr,TreeNode parent){
        this.curr=curr;
        this.parent=parent;
    }
}
class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        Queue<Pair>q = new LinkedList<>();
        if(root==null){
            return false;
        }
        q.add(new Pair(root,null));
        while(!q.isEmpty()){
            int size=q.size();
            TreeNode px = null;
            TreeNode py = null;
            for(int i=0;i<size;i++){
                Pair p = q.poll();
                TreeNode node = p.curr;
                TreeNode node_parent = p.parent;
                if(node.val==x){
                    px = node_parent;
                }
                if(node.val==y){
                    py = node_parent;
                }
                if(node.left!=null){
                    q.add(new Pair(node.left,node));
                }
                if(node.right!=null){
                    q.add(new Pair(node.right,node));
                }
            }
            if(px!=null && py!=null && px!=py){
                return true;
            }
        }
        return false;
    }
}