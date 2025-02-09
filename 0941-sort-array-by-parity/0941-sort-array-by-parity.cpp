class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();

        vector<int> track(n,-1);

        for(int i=0; i<n; i++){
            if(nums[i]&1)track[i] = 1;
        }

        vector<int> res(n, 0);

        int i=0, j=0;

        while(i<n){
            if(track[i]==-1){
                res[j] = nums[i];
                j++;
            }
            i++;
        }
        i=0;
        while(i<n){
            if(track[i]!=-1){
                res[j] = nums[i];
                j++;
            }
            i++;
        }
        return res;
    }
};