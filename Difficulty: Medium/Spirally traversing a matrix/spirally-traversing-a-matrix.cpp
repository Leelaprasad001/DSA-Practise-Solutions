//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();
        int cnt=n*m;
        int l=0,r=m-1,u=0,d=n-1;
        while(cnt>0){
            // ltr
            for(int j=l;j<=r && cnt>0;j++){
                cnt--;
                ans.push_back(mat[u][j]);
            }
            u++;
            // utd
            for(int i=u;i<=d && cnt>0 ;i++){
                cnt--;
                ans.push_back(mat[i][r]);
            }
            r--;
            // rtl
            for(int j=r;j>=l && cnt>0;j--){
                cnt--;
                ans.push_back(mat[d][j]);
            }
            d--;
            // dtu
            for(int i=d;i>=u && cnt>0 ;i--){
                cnt--;
                ans.push_back(mat[i][l]);
            }
            l++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends