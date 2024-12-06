class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> myset(banned.begin(), banned.end());

        int i = 1;
        int cnt = 0;
        int sum = 0;
        while(i<=n){
            if(myset.find(i) == myset.end()){
                if(sum+i<=maxSum){
                    cnt++;
                    sum = sum + i;
                }
            }
            i++;
        }
        return cnt;
    }
};