class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int res = 0, prev = intervals[0][1];  
        for(int i = 1; i < intervals.size(); i++){
            if(prev > intervals[i][0])
                res++;
            else
                prev = intervals[i][1];
        }
        
        return res;
    }
};