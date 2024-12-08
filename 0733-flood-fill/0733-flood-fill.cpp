class Solution {

    private:
    void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>&img, int color, vector<int> &delrow, vector<int> &delcol, int iniColor){
        if(ans[row][col] == color)return;
        ans[row][col] = color;

        int n = img.size();
        int m = img[0].size();

        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && ans[nrow][ncol] == iniColor){
                dfs(nrow, ncol, ans, img, color, delrow, delcol, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int iniColor = img[sr][sc];
        vector<vector<int>> ans = img;

        vector<int> delrow = {-1, 0, +1, 0};
        vector<int> delcol = {0, +1, 0, -1};

        dfs(sr, sc, ans, img, color, delrow, delcol, iniColor);
        return ans;    
    }
};