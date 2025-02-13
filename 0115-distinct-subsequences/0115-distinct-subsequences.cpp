class Solution {
public:

    #define ll long long
    int numDistinct(string s, string t) {
        ll n = s.length();
        ll m = t.length();

        vector<vector<double>> dp(n+1, vector<double> (m+1, 0));

        for(ll i=0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(ll j=1; j<=m; j++){
            dp[0][j] = 0;
        }

        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return int(dp[n][m]);
    }
};
