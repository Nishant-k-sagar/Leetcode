class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int step1 = 1, step2 = 2;
        for (int i = 3; i <= n; ++i) {
            int curr = step1 + step2;
            step1 = step2;
            step2 = curr;
        }
        
        return step2;
    }
};
