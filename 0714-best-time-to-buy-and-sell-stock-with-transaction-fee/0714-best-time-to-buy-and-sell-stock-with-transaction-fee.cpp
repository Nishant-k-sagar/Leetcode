class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();

        int aheadNotBuy, aheadBuy, curBuy, curNotBuy;

        aheadNotBuy = aheadBuy = 0;

        for(int i = n-1; i>=0; i--){
            curNotBuy = max(p[i] + aheadBuy, aheadNotBuy);
            curBuy = max(-p[i] - fee + aheadNotBuy, aheadBuy);

            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};