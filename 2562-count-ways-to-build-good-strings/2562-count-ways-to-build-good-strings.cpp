class Solution {
public:
    int M = 1e9+7;
    int solve(vector<int> &dp, int len, int low, int high, int zero, int one){
        if(len>high)return 0;
        if(dp[len]!=-1)return dp[len];
        int cnt = 0;
        if(len<=high and len>=low)cnt = cnt+1;
        int ans_zero = solve(dp, len+zero,low,high,zero,one);
        int ans_one = solve(dp, len+one,low,high,zero,one);
        return dp[len] = (cnt + ans_zero + ans_one)%M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {

        vector<int>dp(high+1, -1);
        int ans = solve(dp, 0,low,high,zero,one);
        return ans;
    }
};