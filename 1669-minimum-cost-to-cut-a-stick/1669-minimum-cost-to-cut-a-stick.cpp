class Solution {
public:
    int dp[1001][1001];
    
    int solve(vector<int>& cuts, int l, int r) {
        if (l + 1 >= r) return 0;

        if (dp[l][r] != -1) return dp[l][r];
        
        int ans = INT_MAX;
        for (int i = l + 1; i <= r-1; ++i) {
            ans = min(ans, cuts[r] - cuts[l] + solve(cuts, l, i) + solve(cuts, i, r));
        }
        
        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        return solve(cuts, 0, cuts.size() - 1);
    }
};
