class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int n = p.size();

        vector<vector<int>> after(2, vector<int> (3,0));
        vector<vector<int>> cur(2, vector<int> (3,0));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap = 1; cap<=2; cap++){
                    if(buy == 1){
                        cur[buy][cap] = max(-p[i] + cur[0][cap], after[1][cap]);
                    }
                    else {
                        cur[buy][cap] = max(p[i] + after[1][cap-1], after[0][cap]);
                    }
                }
            }
            after = cur;
        }
        return cur[1][2];
    }
};