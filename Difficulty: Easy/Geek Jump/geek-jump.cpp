//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        
        //using dp(tabulation)
        vector<int> dp(n, 1);
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            int J2 = INT_MAX;
            int J1 = dp[i-1] + abs(height[i] - height[i-1]);
            if(i > 1)
                J2 = dp[i-2] + abs(height[i] - height[i-2]);
            dp[i] = min(J1, J2);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends