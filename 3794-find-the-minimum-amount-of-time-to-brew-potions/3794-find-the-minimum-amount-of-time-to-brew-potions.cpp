class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> dp(n, 0);

        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + skill[i];
        }

        long long sum = (long long) skill[0] * mana[0];

        for (int j = 1; j < m; j++) {
            long long time = (long long) skill[0] * mana[j];

            for (int i = 1; i < n; i++) {
                long long tDiff = dp[i] * mana[j - 1] - dp[i - 1] * mana[j];
                if (tDiff > time) {
                    time = tDiff;
                }
            }

            sum += time;
        }

        return sum + dp[n - 1] * mana[m - 1];
    }
};
