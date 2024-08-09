//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> parent, size;
	int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    } 
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        int V = n * m;
        parent.resize(V + 1);
        size.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        for(auto it:operators){
            int r = it[0], c = it[1];
            if(vis[r][c] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[r][c] = 1;
            cnt++;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int ind = 0; ind < 4; ind++){
                int adjr = r + dr[ind];
                int adjc = c + dc[ind];
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                    if(vis[adjr][adjc] == 1){
                        int nodeNo = r * m + c;
                        int adjNodeNo = adjr * m + adjc;
                        if(findUPar(nodeNo) != findUPar(adjNodeNo)){
                            cnt--;
                            unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends