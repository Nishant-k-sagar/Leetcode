namespace std {
template <> struct hash<pair<int, int>> {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
}

class Solution {
private:
    void bfs(vector<vector<char>>& grid, int i, int j,
             unordered_set<pair<int, int>>& vis, vector<pair<int, int>>& dirs,
             int r, int c) {
        queue<pair<int, int>> q;
        vis.insert({i, j});
        q.push({i, j});

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < r && nc >= 0 && nc < c &&
                    grid[nr][nc] == '1' && vis.find({nr, nc}) == vis.end()) {
                    q.push({nr, nc});
                    vis.insert({nr, nc});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int r = grid.size();
        int c = grid[0].size();

        unordered_set<pair<int, int>> vis;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1' && vis.find({i, j}) == vis.end()) {
                    cnt++;
                    bfs(grid, i, j, vis, dirs, r, c);
                }
            }
        }
        return cnt;
    }
};
