class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxF = 0, hash[26] = {0};
        
        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);
            
            //calculating number of element to replace and checking with k 
            if((r - l + 1) - maxF > k){
                hash[s[l] - 'A']--;
                l++;
            }
            
            //updating maxLen length
            if((r - l + 1) - maxF <= k)
                maxLen = max(maxLen, (r - l + 1));
            r++;
        }
        
        return maxLen;
    }
};