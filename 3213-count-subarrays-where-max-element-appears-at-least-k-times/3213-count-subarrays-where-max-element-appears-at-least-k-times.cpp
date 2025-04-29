class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());

        long long ans = 0;

        int left = 0;

        int counter = 0;

        for(int right = 0; right<n; right++){
            if(nums[right] == maxi){
                counter++;
            }

            while(counter == k){
                if(nums[left] == maxi){
                    counter--;
                }
                left++;
                // ans++;
            }
            ans+=left;
        }
        return ans;
    }
};