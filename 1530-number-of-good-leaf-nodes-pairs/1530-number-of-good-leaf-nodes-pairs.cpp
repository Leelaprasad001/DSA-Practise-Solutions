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
     vector<int> distanceToLeaves(TreeNode* cur, int& cnt, int dist){
        if(cur == nullptr) 
            return {};
        if(cur->left == nullptr && cur->right == nullptr){
            return {1};
        }

        vector<int> lefts = distanceToLeaves(cur->left, cnt, dist);
        vector<int> rights = distanceToLeaves(cur->right, cnt, dist);
        vector<int> res(lefts.size() + rights.size()); 

        int i = lefts.size() - 1, j = 0; 
        for(; i >= 0; i--){ // O(L + R)
            while(j < rights.size() && lefts[i] + rights[j] <= dist){
                j++;
            }
            cnt += j; 
        }
        // create sorted results 
        int l = 0, r = 0, idx = 0;
        while(l < lefts.size() && r < rights.size()){ // O(L + R)
            if(lefts[l] < rights[r]){
                res[idx++] = lefts[l++] + 1;
            }else{
                res[idx++] = rights[r++] + 1;
            }
        }
        while(l < lefts.size()){
            res[idx++] = lefts[l++] + 1;
        }
        while(r < rights.size()){
            res[idx++] = rights[r++] + 1;
        }
      
        return res; 
    }
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        distanceToLeaves(root, cnt, distance);
        return cnt;
    }
};