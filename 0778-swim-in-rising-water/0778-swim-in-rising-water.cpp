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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, pair<int,int>>> cells;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cells.push_back({grid[i][j], {i, j}});
            }
        }
        
        sort(cells.begin(), cells.end());
        int V = n * n;
        parent.resize(V + 1);
        size.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
        for (const auto& cell : cells) {
            int elevation = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;
            int index = x * n + y;

            for (const auto& d : directions) {
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    int nIndex = nx * n + ny;
                    if (grid[nx][ny] <= elevation) {
                        unionBySize(index, nIndex);
                    }
                }
            }

            if (findUPar(0) == findUPar(n * n - 1)) {
                return elevation;
            }
        }

        return -1;
    }
};