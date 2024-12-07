class Solution {
    private:
    void dfs(int node, vector<vector<int>> &isConn, vector<int> &vis){
        vis[node] = 1;

        for(int i=0; i<isConn.size(); i++){
            if(isConn[node][i] && !vis[i]){
                dfs(i, isConn, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConn) {
        int n = isConn.size();

        int cnt = 0;

        vector<int> vis(n,0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, isConn, vis);
            }
        }
        return cnt;
    }
};