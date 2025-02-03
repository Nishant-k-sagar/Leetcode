class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();


        if(n==2){
            if(nums[0]==nums[1])return 1;
            else return 2;
        }
        int maxi = 1;
        int cnt = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i]-nums[i+1]>=1){
                cnt++;
                maxi = max(cnt, maxi);
            }
            else {
                cnt = 1;
            }
        }

        for(int i=n-1; i>0; i--){
            if(nums[i]-nums[i-1]>=1){
                cnt++;
                maxi = max(cnt, maxi);
            }
            else {
                cnt = 1;
            }
        }
        return maxi;
    }
};