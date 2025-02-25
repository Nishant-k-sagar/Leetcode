class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for(int idx = 1; idx<n; idx++){
            int take = nums[idx];
            if(idx>1) take += dp[idx-2];

            int notTake = dp[idx-1];

            dp[idx] = max(take, notTake);
        }

        return dp[n-1];
    }
};