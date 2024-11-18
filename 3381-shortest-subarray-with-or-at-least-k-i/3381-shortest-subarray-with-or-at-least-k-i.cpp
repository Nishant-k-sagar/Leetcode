class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = INT_MAX;

        for (int i =0; i< n; i++) {
            int OR =0;
            for (int j =i; j < n; j++) {
                OR |=nums[j];
                if (OR>=k) {
                    len =min(len, j - i + 1);
                }
            }
        }
        
        return (len==INT_MAX) ?-1 : len;
    }
};
