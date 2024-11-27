class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bool flag = false;
        int n=nums.size();
        for(int i= 1; i<n; i++){
            if(nums[i]==nums[i-1])flag=true;
        }
        return flag;
    }
};