class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        vector<int> v;

        for(int i=0; i<n; i++){
            if(nums[i] == target)v.push_back(i);
        }
        return v;
    }
};