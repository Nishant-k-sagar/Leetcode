class Solution {
public:
    int findMinDistance(vector<vector<int>> &adjList, int n) {
        vector<int> dp(n);
        dp[n - 1] = 0;  

        for (int currNode = n - 2; currNode >= 0; currNode--) {
            int minDis = n;

            for (auto neighbor : adjList[currNode]) {
                minDis = min(minDis, dp[neighbor] + 1);
            }
            dp[currNode] = minDis;  
        }
        return dp[0];
    }

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries) {
        vector<int> ans;
        vector<vector<int>> adjList(n, vector<int>(0));

        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
        }

        for (auto &road : queries) {
            int u = road[0];
            int v = road[1];
            adjList[u].push_back(v);

            ans.push_back(findMinDistance(adjList, n));
        }
        return ans;
    }
};