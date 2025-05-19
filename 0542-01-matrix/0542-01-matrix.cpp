class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0)), dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Push all 0s into the queue for BFS start
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1; // Mark 0s as visited
                }
            }
        }
        
        int delRow[] = {-1, 0, 1, 0}, delCol[] = {0, 1, 0, -1};
        
        // BFS
        while (!q.empty()) {
            int r = q.front().first.first, c = q.front().first.second, steps = q.front().second;
            q.pop();
            dist[r][c] = steps; // Update distance
            
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + delRow[i], ncol = c + delCol[i];
                // Add valid, unvisited neighbors to the queue, check boundary conditions
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        
        return dist;
    }
};