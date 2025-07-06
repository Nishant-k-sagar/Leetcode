class Solution {
public:
    int smallestNumber(int n) {
        int len = log2(n);
        for(int i=  0; i<len; i++){
            n |= (1<<i);
        }
        return n;
    }
};