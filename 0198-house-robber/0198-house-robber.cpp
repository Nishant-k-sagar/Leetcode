class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev1 = nums[0];
        int prev2 = 0;

        for(int idx = 1; idx<n; idx++){
            int take = nums[idx];
            if(idx>1) take += prev2;

            int notTake = prev1;

            int cur = max(take, notTake);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};