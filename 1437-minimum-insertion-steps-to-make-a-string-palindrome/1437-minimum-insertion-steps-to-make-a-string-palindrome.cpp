class Solution {
public:

    int lcs(string &s, string &r, vector<vector<int>> &dp){
        int n = s.length();

        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }

        for(int j = 0; j<=n; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1]==r[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string r = s;
        reverse(r.begin(), r.end());

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return n- lcs(s, r, dp);

    }
};