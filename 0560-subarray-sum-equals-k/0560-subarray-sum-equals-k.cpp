class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0, prefix=0;
        map<int,int> m;
        m[0] = 1;
        for(auto x:nums)
        {
            prefix += x;
            int remove = prefix-k;
            count += m[remove];
            m[prefix] += 1;
        }
        return count;
    }
};