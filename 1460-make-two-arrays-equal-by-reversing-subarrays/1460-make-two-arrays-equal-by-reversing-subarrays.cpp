class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        if (n != arr.size()) {
            return false;
        }
        vector<int> count(1001);
        for (int i = 0; i < n; ++i) {
            ++count[target[i]];
            --count[arr[i]];
        }
        
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }
        
        return true;
    }
};