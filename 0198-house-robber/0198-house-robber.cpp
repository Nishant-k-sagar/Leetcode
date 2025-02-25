class Solution {
public:
    int cal(int idx, vector<int> &nums, vector<int> &dp){
        // int sum = 0;

        //base cases
        if(idx == 0){
            return nums[idx];
        }

        if(idx<0){
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        //pick the index,
        int pick = nums[idx] + cal(idx-2, nums, dp);

        //not pick the index
        int notPick = cal(idx-1, nums, dp);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return cal(n-1, nums, dp);
    }
};