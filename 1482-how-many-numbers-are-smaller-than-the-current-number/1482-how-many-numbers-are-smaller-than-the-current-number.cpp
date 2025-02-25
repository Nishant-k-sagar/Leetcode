class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        unordered_map<int, int> mp;

        sort(temp.begin(), temp.end());
     
        for(int i=0;i<n;i++){
            if(mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = i;
            }
        }

        for(int i=0;i<n;i++){
            temp[i] = mp[nums[i]];
        }
        return temp;
    }
};