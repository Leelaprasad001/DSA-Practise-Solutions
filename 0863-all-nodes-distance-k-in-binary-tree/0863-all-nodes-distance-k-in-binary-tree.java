/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    Map<TreeNode, TreeNode> pMap = new HashMap<>();
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        
        List<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        
        helper(root, null);
        
        Queue<TreeNode> q = new LinkedList<>();
        Set<TreeNode> vis = new HashSet<>();
        q.add(target);
        vis.add(target);
        int curr = 0;
        
        while (!q.isEmpty()) {
            if (curr == k) {
                for (TreeNode node : q) {
                    res.add(node.val);
                }
                return res;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode currNode = q.poll();
                if(currNode.left != null && !vis.contains(currNode.left)) {
                    q.add(currNode.left);
                    vis.add(currNode.left);
                }
                if(currNode.right != null && !vis.contains(currNode.right)) {
                    q.add(currNode.right);
                    vis.add(currNode.right);
                }
                TreeNode parentNode = pMap.get(currNode);
                if (parentNode != null && !vis.contains(parentNode)) {
                    q.add(parentNode);
                    vis.add(parentNode);
                }
            }
            curr++;
        }
        return res;
    }
    public void helper(TreeNode node, TreeNode parent) {
        if (node == null) {
            return;
        }
        pMap.put(node, parent);
        helper(node.left, node);
        helper(node.right, node);
    }
}