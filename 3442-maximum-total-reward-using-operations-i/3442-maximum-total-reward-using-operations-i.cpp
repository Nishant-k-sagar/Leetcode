int dp[2001][4001];

class Solution {
public:
    int maxTotalReward(vector<int>& arr) {
        int n = arr.size();
        vector<int> nums;
        unordered_set<int> st(arr.begin(), arr.end());

        memset(dp, -1, sizeof(dp));

        for(auto &it: st){
            nums.push_back(it);
        }

        sort(nums.begin(), nums.end());

        int ans = fun(0, 0, nums);
        return ans;
    }

    int fun(int idx, int sum, vector<int> &nums){
        if(idx == nums.size())return 0;

        int ans = -1;

        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }

        if(nums[idx]>sum){
            ans = max(ans, nums[idx] + fun(idx + 1, sum + nums[idx], nums));
            ans = max(ans, fun(idx+1, sum, nums));
        }
        else {
            ans = max(ans, fun(idx + 1, sum, nums));
        }

        return dp[idx][sum] = ans;
    }
};