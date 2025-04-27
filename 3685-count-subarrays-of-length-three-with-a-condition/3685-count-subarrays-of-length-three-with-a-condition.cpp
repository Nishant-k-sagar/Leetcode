class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int l = 0;
        int r = 2;

        int n =nums.size();

        if(n<=2){
            return 0;
        }
        
        int cnt = 0;
        while(r<n){
            if((nums[l] + nums[r])*2 == nums[l+1])cnt++;
            l++;
            r++;
        }
        return cnt;
    }
};