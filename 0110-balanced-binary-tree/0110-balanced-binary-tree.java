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
    public int height(TreeNode node) 
    {
        if(node == null)
            return 0;
        int maxL = height(node.left);
        int maxR = height(node.right);
        
        return Math.max(maxL, maxR) + 1;
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null)
            return true;
        int leftH = height(root.left);
        int rightH = height(root.right);
        
        if(Math.abs(leftH - rightH) <= 1 && isBalanced(root.left) && isBalanced(root.right))
            return true;
        return false;
    }
}