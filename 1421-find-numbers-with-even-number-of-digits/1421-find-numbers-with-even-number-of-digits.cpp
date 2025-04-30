class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;

        for(int i=0; i<n; i++){
            int dig = log10(nums[i]) + 1;
            // cout<<dig<<" ";
            cnt += (dig&1) == 1 ? 0 : 1;
        }
        return cnt;
    }
};