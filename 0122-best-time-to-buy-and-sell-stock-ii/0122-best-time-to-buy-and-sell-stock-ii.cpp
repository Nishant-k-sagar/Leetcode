class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();

        vector<int>next(2, 0), cur(2,0);

        for(int idx = n-1; idx >= 0; idx --){
            for(int flag = 0; flag<=1; flag++){
                long profit = 0;
                if(flag){
                    profit = max(-p[idx] + next[0], next[1]);
                }
                else 
                profit = max(p[idx] + next[1], next[0]);
            cur[flag] = profit;
            }
            next = cur;
        }
        return next[1];
    }
};