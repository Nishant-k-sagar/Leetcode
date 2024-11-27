class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto e : edges) {
            indegree[e[1]]++;
        }

        int champ = -1, champCnt = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                champCnt++;
                champ = i;
            }
        }

        return champCnt > 1 ? -1 : champ;
    }
};