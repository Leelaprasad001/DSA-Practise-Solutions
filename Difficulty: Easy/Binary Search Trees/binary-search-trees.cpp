//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        bool ans = true;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>=arr[i+1]){
                ans = false;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            nums[i] = k;
        }

        Solution ob;
        bool res = ob.isBSTTraversal(nums);
        if (res)
            cout << "True";
        else
            cout << "False";

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends