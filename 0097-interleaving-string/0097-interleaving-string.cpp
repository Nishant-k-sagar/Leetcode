class Solution {
private:
    vector<vector<int>> dp;
    bool chk(string &s1, int i, string &s2, int j, string &s3, int k){
        if(k == s3.size()){
            if((i == s1.size()) && (j == s2.size()))return true;
            else return false;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool matchs1 = false, matchs2 = false;
        if( i < s1.size() && s1[i] == s3[k]){
            matchs1 = chk(s1, i+1, s2, j, s3, k+1);
        }
        if(j < s2.size() && s2[j] == s3[k]){
            matchs2 = chk(s1, i, s2, j+1, s3, k+1);
        }

        dp[i][j] = matchs1 || matchs2;
        return dp[i][j];
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        // if(s1.size() + s2.size() != s3.size()) return false;
        // dp.assign(s1.size() + 1, vector<int> (s2.size() + 1, -1));
        // return chk(s1, 0, s2, 0, s3, 0);

        int n = s1.size(), m = s2.size();
    if (n + m != s3.size()) return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i > 0)
                dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            if (j > 0)
                dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    return dp[n][m];
    }
};