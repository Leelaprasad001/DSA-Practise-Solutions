//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> val = {x, y, z};
        vector<int> dp(n + 1, -1); 
        dp[0] = 0; 
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i >= val[j] && dp[i - val[j]] != -1) {
                    dp[i] = max(dp[i], dp[i - val[j]] + 1);
                }
            }
        }
        
        return dp[n] == -1 ? 0 : dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends