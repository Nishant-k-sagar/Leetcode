class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int Xor = 0;
        for(int i = 0; i<n; i++){
            Xor^=nums[i];
        }

        int diff = Xor ^ k;

        int cnt = 0;
        for(int i=0; i<32; i++){
            if(diff & (1<<i)){
                cnt++;
            }
        }
        return cnt;
    }
};