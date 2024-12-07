class Solution {
    private:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis){
        vis[node] = 1;

        for( int &it : adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConn) {
        int n = isConn.size();

        vector<int> adjLs[n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConn[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);

        int cnt = 0;

        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};