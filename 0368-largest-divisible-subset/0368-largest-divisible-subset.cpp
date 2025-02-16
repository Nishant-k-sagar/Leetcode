class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), hash(n);

        sort(arr.begin(), arr.end());
        
        int maxi = 1;
        
        int lastIdx = 0;
        for(int i = 0; i<n; i++){
            hash[i] = i;
            for(int prev = 0; prev<i; prev++){
                if((arr[i]%arr[prev] == 0) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        
        vector<int> lis(maxi);
        lis[0] = arr[lastIdx];
        int idx = 1;
        
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            lis[idx++] = arr[lastIdx];
        }
        
        reverse(lis.begin(), lis.end());
        
        return lis;
    }
};