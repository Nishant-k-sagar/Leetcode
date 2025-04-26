class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int cnt = 1;

        int first = nums[0];

        for(int i=0; i<n; i++){
            if(nums[i] - first > k){
                cnt++;
                first = nums[i];
            }
        }
        return cnt;
    }
};