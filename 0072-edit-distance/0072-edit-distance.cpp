class Solution {
public:
    int cnt(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i == 0)return j;
        if(j == 0)return i;

        if(dp[i][j] != -1)return dp[i][j];
        if(s[i-1] == t[j-1]){
            return dp[i][j] = cnt(i-1, j-1, s, t, dp);
        }
        else {
            return dp[i][j] = min(1 + cnt(i-1, j-1, s, t, dp), min(1 + cnt(i-1, j, s, t, dp), 1 + cnt(i, j-1, s, t, dp)));
        }
    }

    int minDistance(string w1, string w2) {
        int n = w1.length();
        int m = w2.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1 , -1));
        return cnt(n, m, w1, w2, dp);
    }
};