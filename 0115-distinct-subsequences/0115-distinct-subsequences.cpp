class Solution {
public:

    #define ld long double
    int numDistinct(string s, string t) {
        ld n = s.length();
        ld m = t.length();

        vector<ld> cur(m+1, 0), prev(m+1, 0);
        prev[0] = cur[0] = 1;

        for(ld i=1; i<=n; i++){
            for(ld j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = prev[j-1] + prev[j];
                }
                else cur[j] = prev[j];
            }
            prev = cur;
        }
        return int(prev[m]);
    }
};
