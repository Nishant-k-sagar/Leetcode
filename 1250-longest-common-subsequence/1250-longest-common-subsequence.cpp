class Solution {
public:

    int lcs(string &t1, string &t2, int i, int j, vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(t1[i]==t2[j]){
            return dp[i][j] = 1 + lcs(t1, t2, i-1, j-1, dp);
        }
        return dp[i][j] = max(lcs(t1, t2, i, j-1, dp), lcs(t1, t2, i-1, j, dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>>dp(n, vector<int> (m, -1));
        return lcs(t1, t2, n-1, m-1, dp);
    }
};