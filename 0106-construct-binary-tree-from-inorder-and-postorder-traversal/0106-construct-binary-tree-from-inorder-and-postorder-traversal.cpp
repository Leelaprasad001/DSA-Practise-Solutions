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
    TreeNode* solve(vector<int>& inorder, int iS, int iE, vector<int>& postorder, int pS, int pE, map<int, int>& mp) {
        
        if(iS > iE || pS > pE)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[pE]);
        int inRoot = mp[postorder[pE]];
        int numsLeft = inRoot - iS;
        
        root->left = solve(inorder, iS, inRoot - 1, postorder, pS, pS + numsLeft - 1, mp);
        root->right = solve(inorder, inRoot + 1, iE, postorder, pS + numsLeft, pE - 1, mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size())
            return NULL;
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        return solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
    }
};