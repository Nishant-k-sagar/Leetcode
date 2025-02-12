class Solution {
public:

    int helper(string &s, string &t, vector<int> &cur, vector<int> &prev){
        int n = s.length();
        int m = t.length();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1])cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return cur[m];
    }

    int minDistance(string w1, string w2) {
        int n = w1.length();
        int m = w2.length();

        vector<int> cur(m+1, 0), prev(m+1, 0);

        return n + m - 2 * helper(w1, w2, cur, prev);
    }
};