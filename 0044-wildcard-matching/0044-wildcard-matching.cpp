class Solution {
public:
    int check(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;

        if (j < 0) {
            for (int idxi = 0; idxi <= i; idxi++) {
                if (p[idxi] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if (p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = check(i - 1, j - 1, p, s, dp);
        }

        if (p[i] == '*') {
            return dp[i][j] = check(i - 1, j, p, s, dp) || check(i, j - 1, p, s, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return check(n - 1, m - 1, p, s, dp);
    }
};
