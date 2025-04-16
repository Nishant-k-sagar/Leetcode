class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);

        for(int i=1; i<=n; i++){
            res[i] = res[i>>1] + (i&1);
            //devide number by 2 or shift lift and check for parity if bit is set
        }
        return res;
    }
};