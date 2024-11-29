class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0], row = curr[1], col = curr[2];

            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            if (vis[row][col]) {
                continue;
            }
            vis[row][col] = true;

            for (auto& d : dirs) {
                int nrow = row + d[0], ncol = col + d[1];
                if (!isValid(vis, nrow, ncol)) {
                    continue;
                }


                int waitTime =
                    ((grid[nrow][ncol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nrow][ncol] + waitTime, time + 1);
                pq.push({nextTime, nrow, ncol});
            }
        }
        return -1;
    }

private:

    bool isValid(vector<vector<bool>>& vis, int row, int col) {
        return row >= 0 && col >= 0 && row < vis.size() &&
               col < vis[0].size() && !vis[row][col];
    }
};