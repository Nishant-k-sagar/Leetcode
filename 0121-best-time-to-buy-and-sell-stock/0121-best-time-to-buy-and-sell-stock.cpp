class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();

        int mini = p[0];
        int profit = 0;

        for(int i = 1; i<n; i++){
            int profitMargin = p[i] - mini; 
            profit = max(profit, profitMargin);
            mini = min(mini, p[i]);
        }
        return profit;
    }
};