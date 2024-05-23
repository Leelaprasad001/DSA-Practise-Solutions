class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int mx = 0, nz = 0, l = 0;
        for(int r=0;r<nums.size();r++){
            if(nums[r] == 0)
                nz++;
            while(nz > k){
                if(nums[l]==0)
                    nz--;
                l++;
            }
            
            int w = r - l + 1;
            mx = max(mx, w);
        }
        
        return mx;
    }
};