class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> orig = nums;
        sort(nums.begin(), nums.end());

        int j = n-1;
        int i = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum == target){
                el1 = nums[i];
                el2 = nums[j];
                break;
            }
            else if(sum>target){
                j--;
            }
            else i++;
        }
        int idx1 = -1;
        int idx2 = -1;
        for(int i = 0; i<n; i++){
            if(el1 == orig[i] && idx1 == -1)idx1 = i;
            else if(el2 == orig[i] && idx2 == -1)idx2 = i;
        }
        return {idx1, idx2};
    }
};