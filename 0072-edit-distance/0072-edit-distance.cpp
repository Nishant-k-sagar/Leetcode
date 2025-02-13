class Solution {
public:
    int cnt(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0)return j+1;
        if(j<0)return i+1;

        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = cnt(i-1, j-1, s, t, dp);
        }
        else {
            return dp[i][j] = min(1 + cnt(i-1, j-1, s, t, dp), min(1 + cnt(i-1, j, s, t, dp), 1 + cnt(i, j-1, s, t, dp)));
        }
    }

    int minDistance(string w1, string w2) {
        int n = w1.length();
        int m = w2.length();

        vector<vector<int>> dp(n, vector<int> (m , -1));
        return cnt(n-1, m-1, w1, w2, dp);
    }
};