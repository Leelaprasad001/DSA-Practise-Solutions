class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq_map;
        // Count the frequency of each number
        for (int num : nums) {
            freq_map[num]++;
        }
        
        // Sort based on frequency and value
        sort(nums.begin(), nums.end(), [&freq_map](int a, int b) {
            // If frequencies are different, sort by frequency
            if (freq_map[a] != freq_map[b]) {
                return freq_map[a] < freq_map[b];
            }
            // If frequencies are the same, sort by value in decreasing order
            return a > b;
        });
        
        return nums;
    }
};