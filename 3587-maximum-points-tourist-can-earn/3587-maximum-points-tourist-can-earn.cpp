class Solution {
public:
    // ss->stayScore
    // ts->travelScore
    int maxScore(int n, int k, vector<vector<int>>& ss,
                 vector<vector<int>>& ts) {
        vector<vector<int>> dp(n, vector<int>(k, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, helper(i, 0, n, k, ss, ts, dp));
        }
        return ans;
    }

    int helper(int city, int day, int n, int k, vector<vector<int>>& ss,
               vector<vector<int>>& ts, vector<vector<int>>& dp) {
        if (city >= n || day >= k)
            return 0;

        if (dp[city][day] != -1)
            return dp[city][day];

        int stay = ss[day][city] + helper(city, day + 1, n, k, ss, ts, dp);

        int notStay = 0;

        for (int i = 0; i < n; i++) {
            if (i != city)
                notStay = max(notStay, ts[city][i] + helper(i, day + 1, n, k,
                                                            ss, ts, dp));
        }

        return dp[city][day] = max(stay, notStay);
    }
};