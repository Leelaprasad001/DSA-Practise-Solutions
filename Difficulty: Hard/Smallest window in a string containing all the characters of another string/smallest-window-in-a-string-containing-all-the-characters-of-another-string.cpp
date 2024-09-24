//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        vector<int>need(26), have(26);
        for(auto &ch : p)
            need[ch - 'a']++;
        
        auto isvalid = [&]() -> bool {
            for(int i = 0; i < 26; i++){
                if(need[i] > have[i])
                    return false;
            }
            return true;
        };
        
        int j = 0, n = s.length(), mnlen = n + 2, start = -1;
        for(int i = 0; i < n; i++){
            have[s[i] - 'a']++;
            while(j <= i && isvalid()){
                int currlen = i - j + 1;
                if(currlen < mnlen){
                    mnlen = currlen;
                    start = i - mnlen + 1;
                }
                have[s[j++] - 'a']--;
            }
        }
        
        if(start == -1)
            return "-1";
        return s.substr(start, mnlen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends