class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int maxi = 0;

        for(int right = 0; right < n; right++){
            if(nums[right] == 1){
                maxi = max(maxi, right - left + 1);
            }
            else {
                left = right + 1;
            }
        }
        return maxi;
    }
};