class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;

        vector<bool> prime(n+1,1);
        if(n<=1)return 0;

        for(int i=2;i<n ; i++){
            if(prime[i]){
                cnt++;
                for(int j = i*2; j<n; j=j+i){
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};