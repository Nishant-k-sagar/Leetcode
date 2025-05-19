class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis (n, vector<int> (m, 0));
        vector<vector<int>> dist(n, vector<int> (m, 0));
        
        //((r,c), steps)
        
        queue<pair<pair<int, int>, int>> q;
        
        //make initial vis arr and do bfs from there i.e. push in queue
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
            if(grid[i][j] == 0){
                q.push({{i, j}, 0}); //initial steps = 0 from 1 to 1 itself
                vis[i][j] = 1;
                //q.push({{r, c}, steps});
            }
            else vis[i][j] = 0;
        }
        
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        //bfs
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            
            q.pop();
            
            dist[r][c] = steps;
            
            for(int i=0; i<4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        
        return dist;
    }
};