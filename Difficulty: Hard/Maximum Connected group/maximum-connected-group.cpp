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
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int V = n * n;
        parent.resize(V + 1);
        size.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 0)
                    continue;
                for(int i = 0; i < 4; i++){
                    int newr = r + dr[i];
                    int newc = c + dc[i];
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1){
                        int nodeNo = r * n + c;
                        int adjNodeNo = newr * n + newc;
                        unionBySize(nodeNo, adjNodeNo);
                    }
                }
             }
        }
        
        int mx = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 1)
                    continue;
                set<int> component;
                for(int i = 0; i < 4; i++){
                    int newr = r + dr[i];
                    int newc = c + dc[i];
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n){
                        if(grid[newr][newc] == 1){
                            component.insert(findUPar(newr * n + newc));   
                        }
                    }
                }
                int sizeTotal = 0;
                for(auto it:component)
                    sizeTotal += size[it];
                mx = max(mx, sizeTotal + 1);
            }
        }
        
        for(int cellNo = 0; cellNo < n; cellNo++)
            mx = max(mx, size[findUPar(cellNo)]);
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends