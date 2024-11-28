class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        minObstacles[0][0] = 0;

        deque<array<int, 3>> deq;
        deq.push_back({0, 0, 0});

        while (!deq.empty()) {
            auto curr = deq.front();
            deq.pop_front();
            int obstacles = curr[0], row = curr[1], col = curr[2];

            for (auto& dir : dirs) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (isValid(grid, newRow, newCol) &&
                    minObstacles[newRow][newCol] == INT_MAX) {
                    if (grid[newRow][newCol] == 1) {
                        minObstacles[newRow][newCol] = obstacles + 1;
                        deq.push_back({obstacles + 1, newRow, newCol});
                    } else {
                        minObstacles[newRow][newCol] = obstacles;
                        deq.push_front({obstacles, newRow, newCol});
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1];
    }

private:
    // Helper method to check if the cell is within the grid bounds
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};