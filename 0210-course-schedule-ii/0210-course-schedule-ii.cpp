class Solution {
bool dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj, vector<int> &onPath){
        vis[node] = 1;
        onPath[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(!dfs(it, vis, st, adj, onPath))return false;
            }
            else if (onPath[it]){
                return false;
            }
        }
        onPath[node] = 0;
        st.push(node);
        return true;
    }

public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto it: edges){
            int a = it[0];
            int b = it[1];
            
            adj[b].push_back(a);
        }
        
        vector<int> vis(V, 0);
        vector<int> onPath(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(!dfs(i, vis, st ,adj, onPath)) return {};
            }
        }
        
        vector<int> ans;
        
        while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
        }
        
        return ans;
    }
};