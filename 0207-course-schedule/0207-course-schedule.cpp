class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree){
        queue<int> que;

        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                cnt++;
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    cnt++;
                    que.push(v);
                }
            }
        }
        if(cnt == n) return true;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &it : prerequisites){
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);

            indegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};
