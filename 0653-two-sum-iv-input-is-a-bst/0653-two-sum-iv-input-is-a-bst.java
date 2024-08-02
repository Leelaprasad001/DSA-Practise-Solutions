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
    public void inOrder(TreeNode root, List<Integer> lst){
        if(root == null)
            return;
        inOrder(root.left, lst);
        lst.add(root.val);
        inOrder(root.right, lst);
    }
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> lst = new ArrayList<>();
        inOrder(root, lst);
        int n = lst.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(lst.get(i) + lst.get(j) == k)
                    return true;
            }   
        }
        return false;
    }
}