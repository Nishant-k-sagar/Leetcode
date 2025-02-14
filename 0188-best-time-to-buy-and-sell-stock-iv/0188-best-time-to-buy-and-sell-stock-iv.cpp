class Solution {
public:
    int cnt(int idx, int lim, vector<int> &p, int n, int flag, vector<vector<vector<int>>> &dp) {
        if (lim == 0 || idx == n) return 0;
        
        if (dp[idx][lim][flag] != -1) return dp[idx][lim][flag];

        if (flag) {
            return dp[idx][lim][flag] = max(-p[idx] + cnt(idx + 1, lim, p, n, 0, dp), 
                                     cnt(idx + 1, lim, p, n, 1, dp));
        } else {
            return dp[idx][lim][flag] = max(p[idx] + cnt(idx + 1, lim - 1, p, n, 1, dp), 
                                     cnt(idx + 1, lim, p, n, 0, dp));
        }
    }
    
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return cnt(0, k, p, n, 1, dp);
    }
};
