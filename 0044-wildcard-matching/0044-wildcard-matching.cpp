class Solution {
public:
    int check(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return true;
        if (i == 0 && j > 0) return false;

        if (j == 0 && i>0) {
            for (int idxi = 1; idxi <= i; idxi++) {
                if (p[idxi-1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if (p[i-1] == s[j-1] || p[i-1] == '?') {
            return dp[i][j] = check(i - 1, j - 1, p, s, dp);
        }

        if (p[i-1] == '*') {
            return dp[i][j] = check(i - 1, j, p, s, dp) || check(i, j - 1, p, s, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return check(n, m, p, s, dp);
    }
};
