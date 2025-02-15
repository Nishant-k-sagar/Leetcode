class Solution {
public:
    int cnt(int idx, int buy, vector<int> &p, int n, vector<vector<int>> &dp){
        if(idx >= n) return 0;

        if(dp[idx][buy] != -1)return dp[idx][buy];
        if(buy == 1){
            return dp[idx][buy] = max(-p[idx] + cnt(idx + 1, 0, p, n, dp), cnt(idx+1, 1, p, n, dp));
        }
        else return dp[idx][buy] = max(p[idx] + cnt(idx + 2, 1, p, n, dp), cnt(idx +1, 0, p, n, dp));
    }

    int maxProfit(vector<int>& p) {
        int n = p.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));
        return cnt(0, 1, p, n, dp);
    }
};