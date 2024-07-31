//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int N = arr.size();
        if(N == 0)
            return "";
            
        string res = arr[0];
        for(int i =1; i < N; ++i){
            while(arr[i].find(res) != 0){
                res = res.substr(0, res.length()-1);
                // cout<<res<<endl;
                if(res.empty())
                    return "-1";
            }
            // cout<<endl;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends