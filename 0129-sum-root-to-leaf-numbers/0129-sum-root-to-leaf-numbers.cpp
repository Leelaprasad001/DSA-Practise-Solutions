/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int sum){
        if(!root)
            return 0;
        sum = sum * 10 + root->val;
        if(!root->left && !root->right)
            return sum;
        int leftSum = solve(root->left, sum);
        int rightSum = solve(root->right, sum);
        return leftSum + rightSum;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};