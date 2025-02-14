class Solution {
public:
    int cnt(int idx, int lim, vector<int> &p, int n, int flag, vector<vector<vector<int>>> &dp) {
        if (lim == 0 || idx == n) return 0;
        
        if (dp[idx][lim][flag] != -1) return dp[idx][lim][flag];

        if (flag) {
            dp[idx][lim][flag] = max(-p[idx] + cnt(idx + 1, lim, p, n, 0, dp), 
                                     cnt(idx + 1, lim, p, n, 1, dp));
        } else {
            dp[idx][lim][flag] = max(p[idx] + cnt(idx + 1, lim - 1, p, n, 1, dp), 
                                     cnt(idx + 1, lim, p, n, 0, dp));
        }
        return dp[idx][lim][flag];
    }

    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return cnt(0, 2, p, n, 1, dp);
    }
};
