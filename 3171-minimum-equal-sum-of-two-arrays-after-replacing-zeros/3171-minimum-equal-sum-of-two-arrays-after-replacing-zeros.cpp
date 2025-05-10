#define ll long long 
class Solution {

public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n=  nums1.size();
        int m = nums2.size();
        ll sum1 = 0;
        ll sum2 = 0;
        ll zero1 = 0;
        ll zero2 = 0;

        for(int i=0; i<n; i++){
            sum1+=nums1[i];
            if(nums1[i] == 0){
                sum1++;
                zero1++;
            }
        }

        for(int i=0; i<m; i++){
            sum2+=nums2[i];

            if(nums2[i] == 0){
                sum2++;
                zero2++;
            }
        }

        if(!zero1 && sum2>sum1 || !zero2 && sum1 > sum2){
            return -1;
        }
        return max(sum1, sum2);
    }
};