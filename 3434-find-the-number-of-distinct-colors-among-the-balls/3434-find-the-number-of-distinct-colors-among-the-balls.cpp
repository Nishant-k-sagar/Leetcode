class Solution {
    public:
        vector<int> queryResults(int lim, vector<vector<int>>& q) {
            int n = q.size();
            vector<int> res(n);
            unordered_map<int, int> colMap, ballMap;
    
            for (int i = 0; i < n; i++) {
                int ball = q[i][0], col = q[i][1];
                if (ballMap.find(ball) != ballMap.end()) {
                    int prevColor = ballMap[ball];
                    colMap[prevColor]--;
                    if (colMap[prevColor] == 0) colMap.erase(prevColor);
                }
                ballMap[ball] = col;
                colMap[col]++;
    
                res[i] = colMap.size();
            }
    
            return res;
        }
    };