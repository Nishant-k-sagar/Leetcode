class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> front1(2, 0);
        vector<int> front2(2, 0);
        vector<int> cur(2, 0);

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                cur[1] = max(-p[i] + front1[0], front1[1]);
                cur[0] = max(p[i] + front2[1], front1[0]);
            }
            front2= front1;
            front1 = cur;
        }
        return cur[1];
    }
};