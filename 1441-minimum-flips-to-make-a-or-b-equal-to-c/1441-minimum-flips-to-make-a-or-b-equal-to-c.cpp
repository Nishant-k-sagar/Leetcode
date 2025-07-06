class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

        for(int i=0; i<32; i++){
            int aidx = (a >> i) & 1;
            int bidx = (b >> i) & 1;
            int cidx = (c >> i) & 1;

            if((aidx | bidx) == cidx)continue;
            if(cidx == 1) cnt++;

            else{
                if(aidx == 1)cnt++;
                if(bidx == 1)cnt++;
            }
        }
        return cnt;
    }
};