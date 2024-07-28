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
    public int res = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        solve(root);
        return res;
    }
    
    public int solve(TreeNode root){
        if(root == null)
            return 0;
        
        int leftH = solve(root.left);
        int rightH = solve(root.right);
        
        res = Math.max(res, leftH + rightH);
        
        return Math.max(leftH, rightH) + 1;
    }
}