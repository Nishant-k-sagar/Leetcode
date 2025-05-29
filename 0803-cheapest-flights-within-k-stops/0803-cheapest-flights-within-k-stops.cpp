class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
        }
        //{stops, {nodes, dist}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops>K)continue;
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int edW = iter.second;
                
                if(cost + edW < dist[adjNode] && stops<=K){
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};