class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int i, int j, int n, int m){
        if(i>=n || j>=m)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;

        ans = max(ans, solve(s1, s2, i+1, j, n, m));
        ans = max(ans, solve(s1, s2, i, j+1, n, m));
        if(s1[i]==s2[j])ans = max(ans, 1+ solve(s1, s2, i+1, j+1, n, m));

        return dp[i][j] = ans;

    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        memset(dp,-1,  sizeof(dp));
        return solve(text1, text2, 0, 0, n, m);

    }
};