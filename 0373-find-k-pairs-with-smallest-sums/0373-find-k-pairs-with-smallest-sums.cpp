class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0; i < nums1.size(); i++)
            pq.push({nums1[i] + nums2[0], {i, 0}});
            
        while(k-- && !pq.empty()){
            auto topEle = pq.top();
            pq.pop();
            int i = topEle.second.first;
            int j = topEle.second.second;
            res.push_back({nums1[i], nums2[j]});
            if(j + 1 < nums2.size())
                pq.push({nums1[i] + nums2[j+1], {i, j + 1}});
        }
        return res;
    }
};