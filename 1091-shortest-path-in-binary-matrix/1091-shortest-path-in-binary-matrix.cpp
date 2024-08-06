class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        mat[0][0] = 1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<int> dr = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dc = {1, -1, 0, 0, 1, -1, 1, -1};
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            int dist = mat[x][y];
            
            for (int i = 0; i < 8; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                
                if (0 <= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] == 0) {
                    if (dist + 1 < mat[nx][ny]) {
                        mat[nx][ny] = dist + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        int ans = mat[n-1][n-1];
        if (ans == 1e9) return -1;
        return ans;
    }
};