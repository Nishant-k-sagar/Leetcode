class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n>0){
            int lsb = n&1;
            if(lsb)cnt++;
            n=n>>1;
        }
        return cnt;
    }
};