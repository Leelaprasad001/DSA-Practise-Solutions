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
    void solve(TreeNode* root, vector<string> &res, string a){
        if(root == NULL)
            return;
        if(!a.empty()) {
            a += "->";
        }
        a += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            res.push_back(a);
        }
        solve(root->left, res, a);
        solve(root->right, res, a);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string a;
        solve(root, res, a);
        return res;
    }
};