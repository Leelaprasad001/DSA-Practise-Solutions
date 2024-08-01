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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        TreeNode* root = solve(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        return root;
    }
    
    TreeNode* solve(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &mp){
        
        if(pStart > pEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;
        root->left = solve(preorder, pStart + 1, pStart + numsLeft, inorder, inStart, inRoot - 1, mp);
        root->right = solve(preorder, pStart + numsLeft + 1, pEnd, inorder, inRoot + 1, inEnd, mp);
        
        return root;
    }
};