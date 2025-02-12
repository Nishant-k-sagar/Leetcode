class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        int result = -1;

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            int sum = 0;
            int temp = nums[i];
            while(temp){
                sum += (temp%10);
                temp /= 10;
            }

            if(mp.count(sum)){
                result = max(result, mp[sum] + nums[i]);
            }

            mp[sum] = max(mp[sum], nums[i]);
        }
        return result;
    }
};