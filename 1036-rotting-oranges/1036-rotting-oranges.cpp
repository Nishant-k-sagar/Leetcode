class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cntFresh = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1)cntFresh++;
            }
        }

        int maxi = 0;

        int drow[] = {0, -1, 0, 1};
        int dcol[] = {1, 0, -1, 0};

        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;

            int time = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                //boundary conditions for the row and col

                if(nrow < n && nrow>=0 && ncol<m && ncol>=0
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, time+1});
                    maxi = max(time+1, maxi);
                    cnt++;
                    vis[nrow][ncol] =2;
                }
            }

        }
        if(cnt != cntFresh)return -1;
        return maxi;
    }
};