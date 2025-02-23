class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n==1)return nums[0];
        return nums[n/2];
    }
};