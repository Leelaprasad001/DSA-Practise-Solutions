class Solution {
public:
    int solve(vector<int>& nums, int k){
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mp;
        while(r < nums.size()){
            mp[nums[r]]++;
            
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};