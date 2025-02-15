class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                dp[i][1] = max(-p[i] + dp[i+1][0], dp[i+1][1]);
                dp[i][0] = max(p[i] + dp[i+2][1], dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};