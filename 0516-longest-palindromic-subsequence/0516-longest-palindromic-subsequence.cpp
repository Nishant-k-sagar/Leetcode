class Solution {
public:

    int lcs(string &s, string &t, vector<int> &prev, vector<int> &cur){
        int n = s.length();

        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1])cur[j] = 1 + prev[j-1];
                else{
                    cur[j] = max(prev[j], cur[j-1]);
                }
                ans = max(ans, cur[j]);
            }
            prev = cur;
        }
        return ans;
    }

    int longestPalindromeSubseq(string s) {
        string t = s;

        reverse(t.begin(), t.end());

        int n = s.length();
        vector<int> prev(n+1, 0), cur(n+1, 0);
        return lcs(s, t, prev, cur);
    }
};