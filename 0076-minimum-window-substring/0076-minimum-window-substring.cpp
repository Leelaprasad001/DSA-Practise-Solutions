class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, cnt = 0, sInd = -1, minLen = INT_MAX;
        unordered_map<char, int> mp;
        
        for(auto c:t)
            mp[c]++;
        
        while(r < s.size()){
            if(mp[s[r]] > 0) 
                cnt++;
            mp[s[r]]--;
            while(cnt == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sInd = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        
        return sInd == -1 ? "" : s.substr(sInd, minLen);
    }
};