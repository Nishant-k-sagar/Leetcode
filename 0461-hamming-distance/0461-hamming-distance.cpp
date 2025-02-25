class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x^y;

        int cnt = 0;
        while(XOR){
            if(XOR & 1)cnt++;
            XOR>>=1;
        }
        return cnt;
    }
};