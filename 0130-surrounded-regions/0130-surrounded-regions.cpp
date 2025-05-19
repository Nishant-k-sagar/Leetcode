class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delRow[], int delCol[]) {
        vis[row][col] = 1; // Mark visited
        
        int n = mat.size(), m = mat[0].size();
        
        // Explore up, down, left, right
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i], ncol = col + delCol[i];
            
            // voundary conditions and other checks
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delRow, delCol); // dfs
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        int delRow[] = {0, -1, 0, 1}, delCol[] = {1, 0, -1, 0};
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // for first and last rows
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O') dfs(0, j, vis, mat, delRow, delCol);
            if (!vis[n-1][j] && mat[n-1][j] == 'O') dfs(n-1, j, vis, mat, delRow, delCol);
        }
        
        //for first and last cols
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, vis, mat, delRow, delCol);
            if (!vis[i][m-1] && mat[i][m-1] == 'O') dfs(i, m-1, vis, mat, delRow, delCol);
        }
        
        // Replace unvisited 'O's with 'X's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }
    }
};