//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        int n = pattern.length();
        int m = str.length();
        
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=1; i<= n; ++i){
            if(pattern[i-1] == '*'){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                } else if(pattern[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] ||dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends