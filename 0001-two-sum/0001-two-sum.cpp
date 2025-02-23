class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        map<int, int> mp;

        for(int i=0; i<n; i++){
            int num = nums[i];
            int Needed = target - num;

            if(mp.find(Needed) != mp.end()){
                return {mp[Needed], i};
            }
            mp[num] = i;
        }
        return {-1, -1};
    }
};