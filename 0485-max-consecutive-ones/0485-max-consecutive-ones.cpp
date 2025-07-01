class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int left = -1;
        int maxLen = 0;
        int cnt = 0;
        for(int right = 0; right<n; right++){
            if(nums[right] == 1 and left == -1) 
            {
                left = right;
                cnt++;
                maxLen = 1;
            }
            else if(nums[right] == 1) {
                cnt++;
                maxLen = max(cnt, maxLen);
            }
            else if(nums[right] == 0){
                left = right;
                cnt = 0;
            }
        }
        return maxLen;
    }
};