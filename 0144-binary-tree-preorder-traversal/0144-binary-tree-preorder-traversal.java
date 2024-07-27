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
    public static List<Integer> res = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
        res.clear();
        preOrder(root);
        return res;
    }
    
    private static void preOrder(TreeNode root){
        if(root == null)
            return;
        res.add(root.val);
        preOrder(root.left);
        preOrder(root.right);
    }
}