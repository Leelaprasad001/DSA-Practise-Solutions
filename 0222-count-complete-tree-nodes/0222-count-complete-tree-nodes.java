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
    public void inOrder(TreeNode root, int[] cnt){
        if(root == null)
            return;
        cnt[0]++;
        inOrder(root.left, cnt);
        inOrder(root.right, cnt);
    }
    public int countNodes(TreeNode root) {
        if(root == null)
            return 0;
        int cnt[] = {0};
        inOrder(root, cnt);
        return cnt[0];
    }
}