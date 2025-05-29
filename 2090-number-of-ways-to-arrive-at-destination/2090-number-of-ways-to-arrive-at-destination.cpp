class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto it : roads){
            long long u = it[0];
            long long v = it[1];
            long long wt = it[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // {dist, node}
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, 1e15), ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        pq.push({0, 0});
        long long mod = (long long)(1e9 + 7);
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            long long node = it.second;
            
            for(auto iter : adj[node]){
                long long adjNode = iter.first;
                long long edW = iter.second;
                
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    // update the number of ways for adjNode 
                    // number of ways to reach adjNode is same as of node i.e. path be == 0----node-->adjNode
                    ways[adjNode] = ways[node]; 
                }
                else if(dis + edW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};