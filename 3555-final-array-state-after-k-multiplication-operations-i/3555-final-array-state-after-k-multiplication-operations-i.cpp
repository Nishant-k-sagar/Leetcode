class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int siz = nums.size();

        for(int i=1; i<=k; i++){
            auto mini = find(nums.begin(), nums.end(), *min_element(nums.begin(), nums.end()));
            int idx = mini - nums.begin();
            nums[idx] = multiplier*nums[idx];
        }
        return nums;
    }
};