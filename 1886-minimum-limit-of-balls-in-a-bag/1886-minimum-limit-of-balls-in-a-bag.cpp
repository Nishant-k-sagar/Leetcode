class Solution {

    bool isPos(vector<int>&nums, int maxOps, int mid){
        int totOps = 0;
        for(int &num: nums){
            int ops = num/mid;
            if(num%mid == 0){
                ops = ops-1;
            }
            totOps = ops+totOps;
        }
        return totOps<=maxOps;;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        int res = r;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPos(nums, maxOperations, mid)){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};