class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();

        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        dp[n][0] = dp[n][1] = 0;

        for(int idx = n-1; idx >= 0; idx --){
            for(int flag = 0; flag<=1; flag++){
                long profit = 0;
                if(flag){
                    profit = max(-p[idx] + dp[idx+1][0], dp[idx+1][1]);
                }
                else 
                profit = max(p[idx] + dp[idx+1][1], dp[idx + 1][0]);
            dp[idx][flag] = profit;
            }
        }
        return dp[0][1];
    }
};