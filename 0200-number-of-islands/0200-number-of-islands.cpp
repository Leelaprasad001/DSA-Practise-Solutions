class Solution {
private:
    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m){
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c] = 1;
        
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + directions[i][0];
                int ncol = col + directions[i][1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(!vis[r][c] && grid[r][c] == '1'){
                    cnt++;
                    bfs(r, c, vis, grid, n, m);
                }
            }
        }
        return cnt;
    }
};