class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        map<string, int> mp;
        
        for(string x:words)
            mp[x]++;
        
        vector<pair<int, string>> temp;
        for(auto it:mp)
            temp.push_back({it.second, it.first});
        
        sort(temp.begin(), temp.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) 
                return a.second < b.second;
            return a.first > b.first;
        });
        
        for(int i = 0; i < temp.size() & k != 0; i++){
            res.push_back(temp[i].second);
            k--;
        }
        return res;
    }
};