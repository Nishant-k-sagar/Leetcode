class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> freq;
        freq[0] = 1; 
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i<n; i++) {
            sum += nums[i];

            if (freq.find(sum - goal) != freq.end()) {
                cnt += freq[sum - goal];
            }

            freq[sum]++;
        }

        return cnt;
    }
};