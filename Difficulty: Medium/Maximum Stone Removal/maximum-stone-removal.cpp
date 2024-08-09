//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // TO find last row, col of last stone
        int maxRow = 0, maxCol = 0;
        for(auto it:stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        int V = (maxRow + maxCol + 1);
        parent.resize(V + 1);
        size.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            int u = it[0];
            //to make col to unique (0,0) -> (0,5) in 5*4 0-index matrix
            int v = it[1] + maxRow + 1;
            unionBySize(u, v);
            stoneNodes[u] = 1;
            stoneNodes[v] = 1;
        }
        
        //find no of components
        int cnt = 0;
        for(auto it:stoneNodes){
            if(findUPar(it.first) == it.first)
                cnt++;
        }
        
        return n - cnt;
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
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends