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
    private TreeNode buildBST(int[] preorder, int[] index, int bound) {
        if (index[0] == preorder.length || preorder[index[0]] > bound) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[index[0]++]);
        root.left = buildBST(preorder, index, root.val);
        root.right = buildBST(preorder, index, bound);
        return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        int[] index = {0};
        return buildBST(preorder, index, Integer.MAX_VALUE);
    }
}