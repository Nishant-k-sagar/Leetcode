class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int check = 0;
        for(int i=0; i<n; i++){
            if(check<0)return false;
            else if(nums[i]>check){
                check = nums[i];
            }
            check -= 1;
        }
        return true;
    }
};