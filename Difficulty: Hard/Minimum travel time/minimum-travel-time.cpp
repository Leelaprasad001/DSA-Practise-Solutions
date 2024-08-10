//{ Driver Code Starts
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
    int Solve(int n, vector<vector<int>>& grid) {
        // code here
        vector<pair<int, pair<int,int>>> cells;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cells.push_back({grid[i][j], {i,j}});
            }
        }
        sort(cells.begin(),cells.end());
        int V = n * n;
        parent.resize(V + 1);
        size.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto it:cells){
            int elev = it.first;
            int x = it.second.first;
            int y = it.second.second;
            int ind = x * n + y;
            for(auto d:directions){
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int nInd= nx * n + ny;
                    if (grid[nx][ny] <= elev) {
                        unionBySize(ind, nInd);
                    }
                }
            }
            if (findUPar(0) == findUPar(n * n - 1)) {
                return elev;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends