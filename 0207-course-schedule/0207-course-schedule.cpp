class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);

        for(auto it : prereq){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
        }

        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return ans.size() == n;
    }
};