class Solution {
private:
    bool issmallpairs(const vector<int>& nums, int k, int mid) {
        int count = 0, left = 0;
        for (int right = 1; right < nums.size(); right++) {
            while (nums[right] - nums[left] > mid) left++;
            count += right - left;
        }
        return (count >= k);
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums[nums.size() - 1] - nums[0];
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (issmallpairs(nums, k, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};