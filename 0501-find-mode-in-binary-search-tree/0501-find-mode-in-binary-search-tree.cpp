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
    vector<int> res;
    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto x:res)
            m[x]++;
        
        int mc = 0;
        for(auto x:m){
            mc = max(mc, x.second);
        }
        for(auto x:m){
            if(x.second == mc)
                ans.push_back(x.first);
        }
        return ans;
    }
};