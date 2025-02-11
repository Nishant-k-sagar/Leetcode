class Solution {
public:

    int lcs(string &t1, string &t2, int i, int j, vector<vector<int>> &dp){
        if(i==0 || j==0)return 0;

        if(dp[i-1][j-1]!=-1)return dp[i-1][j-1];

        if(t1[i-1]==t2[j-1]){
            return dp[i-1][j-1] = 1 + lcs(t1, t2, i-1, j-1, dp);
        }
        return dp[i-1][j-1] = max(lcs(t1, t2, i, j-1, dp), lcs(t1, t2, i-1, j, dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>>dp(n+1, vector<int> (m+1, -1));
        return lcs(t1, t2, n, m, dp);
    }
};