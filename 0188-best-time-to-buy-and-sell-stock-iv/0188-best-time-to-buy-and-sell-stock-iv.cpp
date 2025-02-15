class Solution {
public: 
    int cnt(int ind, int tranNo, vector<int> &p, int n, int k, vector<vector<int>> &dp){
        if(ind == n || tranNo == 2*k) return 0;

        if(dp[ind][tranNo] != -1)return dp[ind][tranNo];
        if(tranNo%2 == 0){
            return dp[ind][tranNo] = max(-p[ind] + cnt(ind+1, tranNo + 1,p, n, k, dp), cnt(ind+1, tranNo, p, n, k, dp));
        }
        return dp[ind][tranNo] = max(p[ind] + cnt(ind+1, tranNo + 1,p, n, k, dp), cnt(ind+1, tranNo, p, n, k, dp));
    }

    int maxProfit(int k, vector<int>& p) {
        int n = p.size();

        vector<vector<int>> dp(n, vector<int> (2*k, -1));
        return cnt(0, 0, p, n, k, dp);
    }
};
