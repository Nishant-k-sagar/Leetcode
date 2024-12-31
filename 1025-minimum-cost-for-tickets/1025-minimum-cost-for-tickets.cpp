class Solution {
public:
    int dp[366];
    int solve(vector<int> &days, vector<int>&costs, int n, int i){
        if(i>=n)return 0;

        if(dp[i]!=-1)return dp[i];
        int cost1 = costs[0]+solve(days, costs, n, i+1);

        int j=i;
        int maxday = days[i]+7;

        while(j<n && days[j]<maxday){
            j++;
        }

        int cost7 = costs[1]+solve(days, costs, n, j);

        j = i;
        maxday = days[i]+30;

        while(j<n && days[j]<maxday){
            j++;
        }

        int cost30 = costs[2]+solve(days, costs, n, j);

        return dp[i] = min({cost1, cost7, cost30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        memset(dp, -1, sizeof(dp));

        return solve(days, costs, n, 0);
    }
};