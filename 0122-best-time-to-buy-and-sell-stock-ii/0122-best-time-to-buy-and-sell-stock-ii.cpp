class Solution {
public:
    long cnt(int i, int flag, vector<int> &p, int n, vector<vector<int>> &dp){
        if(i == n)return 0;
        int profit = 0;

        if(dp[i][flag] != -1)return dp[i][flag];
        if(flag){
            profit =  max(-p[i] + cnt(i+1, 0, p, n, dp), cnt(i+1, 1, p, n, dp));
        }
        else
            profit =  max(p[i] + cnt(i+1, 1, p, n, dp), cnt(i+1, 0, p, n, dp));

        return dp[i][flag] = profit;
    }

    int maxProfit(vector<int>& p) {
        int n = p.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));
        return cnt(0, 1, p, n, dp);
    }
};