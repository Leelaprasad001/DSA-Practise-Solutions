//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string s) {
        // code here
          int n=s.size();
          stack<int>st;
          for(int i=0;i<n;i++){
              if(st.empty()) st.push(i);
              else if(!st.empty()){
                  int idx=st.top();
                  if(s[idx]=='(' && s[i]==')') st.pop();
                  else if(s[i]=='(')st.push(i);
                  else st.push(i);
              }
          }
          int prev=n;
          int ans=0;
          while(!st.empty()){
             
              int val=st.top();
               
              ans=max(ans,prev-val-1);
              prev=val;
              st.pop();
          }
       
          return max(ans,prev);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends