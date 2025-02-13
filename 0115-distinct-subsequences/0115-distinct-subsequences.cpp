class Solution {
public:

    #define ld long double
    int numDistinct(string s, string t) {
        ld n = s.length();
        ld m = t.length();

        vector<vector<ld>> dp(n+1, vector<ld> (m+1, 0));

        for(ld i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(ld j=1; j<=m; j++){
            dp[0][j] = 0;
        }

        for(ld i=1; i<=n; i++){
            for(ld j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return int(dp[n][m]);
    }
};
