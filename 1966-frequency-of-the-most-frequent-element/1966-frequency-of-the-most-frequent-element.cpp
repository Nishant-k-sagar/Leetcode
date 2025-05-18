class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        //in any window of size n, max total can be n * max_element ( using all max elements at once ).
        //if max_sum of window > total + k
        sort(nums.begin(), nums.end());
        long long total = 0;
        long long  left = 0, maxFreq = 0;

        for (long long right = 0; right < nums.size(); right++) {
            total += nums[right];
            
            while (nums[right] * (right - left + 1) > total + k) {
                total -= nums[left];
                left++;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};