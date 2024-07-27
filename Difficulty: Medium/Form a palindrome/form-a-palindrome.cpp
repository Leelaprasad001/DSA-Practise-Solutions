//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(string &str1,string &str2,int i,int j,vector<vector<int>>&dp)
      {
          
          if(i>=str1.length() || j>=str2.length())
          return 0;
          
          if(dp[i][j]!=-1)
          return dp[i][j];
          
          int ans=0;
          if(str1[i]==str2[j])
          ans=1+solve(str1,str2,i+1,j+1,dp);
      
          else
          {
              ans=max(ans,solve(str1,str2,i+1,j,dp));
              ans=max(ans,solve(str1,str2,i,j+1,dp));
          }
          return dp[i][j]=ans;
      }
    int countMin(string str)
    {
        string st=str;
        reverse(st.begin(),st.end());
        vector<vector<int>>dp(str.length(),vector<int>(str.length(),-1));
       return str.length()-solve(str,st,0,0,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends