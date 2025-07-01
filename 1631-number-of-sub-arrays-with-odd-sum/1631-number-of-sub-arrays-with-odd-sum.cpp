class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        int prefix = 0;
        int odd = 0;
        int even = 1;
        int result = 0;

        for(int i=0; i<n; i++){
            prefix += arr[i];
            if(prefix % 2 == 0){
                even++;
                result = (result + odd) % MOD;
            }
            else{
                even = even % MOD;
                result = (result + even) % MOD;
                odd++;
            }
        }
        return result;
    }
};