class Solution {
public:
    int cnt(int idx, int prevIdx, vector<int> &nums, int n, vector<vector<int>> &dp){
        if(idx == n)return 0;

        if(dp[idx][prevIdx +1] != -1) return dp[idx][prevIdx + 1];
        
        int len = cnt(idx+1, prevIdx, nums, n, dp);
        if(prevIdx == -1 || nums[idx]>nums[prevIdx]) len = max(len, 1 + cnt(idx+1, idx, nums, n, dp));
        return dp[idx][prevIdx + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (n+1, -1));

        return cnt(0, -1, nums, n, dp);
    }
};