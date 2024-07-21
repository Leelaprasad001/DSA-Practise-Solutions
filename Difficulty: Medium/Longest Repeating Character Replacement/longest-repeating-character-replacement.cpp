//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int K) {
        // code here
        int l = 0, r = 0, maxLen = 0, maxF = 0, hash[26] = {0};
        
        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);
            if((r-l+1) - maxF > K){
                hash[s[l] - 'A']--;
                l++;
            }
            if((r-l+1) - maxF <= K){
                maxLen = max(maxLen, (r-l+1));
            }
            r++;
        }
        
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends