class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ump;

        for(int i=0; i<nums.size(); i++){
            int val = nums[i];
            if(ump.find(val)!= ump.end() && i-ump[val]<=k)return true;
        ump[val] = i;
        }
    return false;
    }
};