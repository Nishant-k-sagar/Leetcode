class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.length();
        int m = w2.length();

        vector<int> prev(m+1, 0), cur(m+1, 0);

        for(int j=0; j<=m; j++) prev[j] = j;

        for(int i = 1; i<=n; i++){
            cur[0] = i;
            for(int j = 1; j<=m; j++){
                if(w1[i-1] == w2[j-1]){
                    cur[j] = prev[j-1];
                }
                else {
                    cur[j] = min(1 + prev[j-1], min(1 + prev[j], 1 + cur[j-1]));
                }
            }  
            prev = cur;
        }
        return prev[m];
    }
};