class Solution {
    // private:
    //     int maxDiff(vector<int> &piles, int i, int j, vector<vector<int>>
    //     &dp){
    //         if(i == j)return dp[i][j] = piles[i];

    //         if(dp[i][j] != -1) return dp[i][j];
    //         int left = piles[i] - maxDiff(piles, i + 1, j, dp);
    //         int right = piles[j] - maxDiff(piles, i, j - 1, dp);

    //         return dp[i][j] = max(left, right);
    //     }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int left = piles[i] - dp[i + 1][j];
                int right = piles[j] - dp[i][j - 1];
                dp[i][j] = max(left, right);
            }
        }
        return dp[0][n - 1] > 0;
        // return maxDiff(piles, 0, n - 1, dp) > 0;
    }
};