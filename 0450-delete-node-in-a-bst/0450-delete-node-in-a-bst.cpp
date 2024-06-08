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
    TreeNode* minValue(TreeNode* root){
        TreeNode* curr = root;
        while(curr && curr->left != nullptr)
            curr = curr->left;
        return curr;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else{
            if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = minValue(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        
        return root;
    }
};