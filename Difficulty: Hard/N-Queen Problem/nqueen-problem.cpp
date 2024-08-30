//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, vector<int> &leftRow, vector<int> &leftLowerDiagonal, vector<int> &leftUpperDiagonal, int n){
        
        if(col == n){
            vector<int> temp;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(board[j][i])
                        temp.push_back(j + 1);
                }
            }
            ans.push_back(temp);
            return;
        }
        
        for(int row = 0; row < n; row++){
            if(leftRow[row] == 0 && leftLowerDiagonal[row + col] == 0 && leftUpperDiagonal[n-1 + col - row] == 0){
                
                board[row][col] = row + 1;
                leftRow[row] = 1;
                leftLowerDiagonal[row + col] = 1;
                leftUpperDiagonal[n-1 + col - row] = 1;
                
                solve(col + 1, board, ans, leftRow, leftLowerDiagonal, leftUpperDiagonal, n);
                board[row][col] = 0;
                leftRow[row] = 0;
                leftLowerDiagonal[row + col] = 0;
                leftUpperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<int> leftRow(n, 0), leftLowerDiagonal(2*n-1, 0), leftUpperDiagonal(2*n-1, 0);
        solve(0, board, ans, leftRow, leftLowerDiagonal,leftUpperDiagonal, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends