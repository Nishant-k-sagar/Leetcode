class Solution {
public:
    vector<vector<int>> dp;


    Solution() {
        dp = vector<vector<int>>(20001, vector<int>(4, -1));
    }

    int Helper(vector<int>& subarr, int count, int i, int k) {
        if (count == 0) {
            return 0;
        }
        if (i >= subarr.size()) {
            return INT_MIN;
        }

        if (dp[i][count] != -1) {
            return dp[i][count];
        }

        int take = subarr[i] + Helper(subarr, count - 1, i + k, k);
        int not_take = Helper(subarr, count, i + 1, k);

        return dp[i][count] = max(take, not_take);
    }

    void solve(vector<int>& subarr, int count, int i, int k, vector<int>& res) {
        if (count == 0) return;

        if (i >= subarr.size()) {
            return;
        }

        int take_i = subarr[i] + Helper(subarr, count - 1, i + k, k);
        int not_take_i = Helper(subarr, count, i + 1, k);

        if (take_i >= not_take_i) {
            res.push_back(i);
            solve(subarr, count - 1, i + k, k, res);
        } else {
            solve(subarr, count, i + 1, k, res);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> subarr;
        int i = 0, j = 0, windowSum = 0;

        while (j < nums.size()) {
            windowSum += nums[j];
            if (j - i + 1 == k) {
                subarr.push_back(windowSum);
                windowSum -= nums[i];
                i++;
            }
            j++;
        }

        vector<int> res;
        solve(subarr, 3, 0, k, res);
        return res; 
    }
};
