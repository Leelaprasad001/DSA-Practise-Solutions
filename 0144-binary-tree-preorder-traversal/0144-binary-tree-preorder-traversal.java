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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        return preOrder(root, res);
    }
    
    private static List<Integer> preOrder(TreeNode root,List<Integer> res){
        if(root == null)
            return res;
        
        res.add(root.val);
        preOrder(root.left, res);
        preOrder(root.right, res);
        
        return res;
    }
}