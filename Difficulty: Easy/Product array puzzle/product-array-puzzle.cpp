//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    long long int product(int index, vector<long long int>& nums){
        long long int ans = 1;
        for(int i=0; i<nums.size(); i++){
            if(i != index){
                ans *= nums[i];
            }
        }
        return ans;
    } 
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // code here
        int n = nums.size();
        vector<long long int> ans(n,1);
        
        for(int i=0; i<n; i++){
            ans[i] = product(i, nums);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends