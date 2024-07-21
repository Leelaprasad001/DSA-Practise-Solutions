//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int mod=1e9+7;
        int n=arr.size();
        int cp=0,cn=0,cz=0,maxn=INT_MIN;
        long long pop=1,pon=1;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                cz++;
            }
            else if(arr[i]>0){
                cp++;
                pop=(pop*arr[i])%mod;
            }
            else {
                cn++;
                pon=(pon*arr[i])%mod;
                maxn=max(maxn,arr[i]);
            }
        }
        
        int prod=1;
        if(cp==0 && cn==0){
            prod = 0;
        }
        else if(cn==0){
            prod = pop;
        }
        else if(cn%2==0){
            prod = (pop*pon)%mod;
        }
        else if(cn%2!=0){
            prod = (pop*(pon/maxn)%mod)%mod;
        }
        
        return prod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends