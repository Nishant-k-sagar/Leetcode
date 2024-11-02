class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int idx1 = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx1 = i;
                break;
            }
        }
        if(idx1==-1){
            return reverse(nums.begin(), nums.end());
        }

        reverse(nums.begin()+idx1+1, nums.end());

        int idx2 = -1;

        for(int i = idx1; i<n; i++){
            if(nums[i]>nums[idx1]){
                idx2 = i;
                break;
            }
        }

        int temp = nums[idx1];
        nums[idx1]=nums[idx2];
        nums[idx2] = temp;
        return;
    }
};