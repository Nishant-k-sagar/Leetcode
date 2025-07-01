class Solution {
    private:
    int atMostKOdd(vector<int> &nums, int k){
        int left = 0, right = 0;
        int cnt = 0;
        int ans = 0;
        int n = nums.size();

        while(right< n){
            if(nums[right] % 2 != 0){
                k--;
            }
            while(k < 0){
                if(nums[left] % 2 != 0){
                    k++;
                }
                left++;
            }

            ans += right - left + 1;
            right++;
        }
        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKOdd(nums, k) - atMostKOdd(nums, k - 1);
    }
};