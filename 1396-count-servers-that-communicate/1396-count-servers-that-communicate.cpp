class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();    
        int m = grid[0].size(); 

        vector<int> rowcnt(n, 0);    
        vector<int> colcnt(m, 0);    

    
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    rowcnt[row] += 1;
                    colcnt[col] += 1;
                }
            }
        }

        int ans = 0;
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1 && (rowcnt[row] > 1 || colcnt[col] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
