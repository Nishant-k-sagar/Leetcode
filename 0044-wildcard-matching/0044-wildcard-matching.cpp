class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        
        vector<bool> prev(m + 1, false), cur(m + 1, false);
        
        prev[0] = true;
        
        for (int i = 1; i <= n && p[i-1] == '*'; i++) {
            prev[0] = true;
        }
        
        for (int i = 1; i <= n; i++) {
            if (p[i-1] == '*') {
                cur[0] = prev[0];
            } else {
                cur[0] = false;
            }
            
            for (int j = 1; j <= m; j++) {
                if (p[i-1] == '*') {
                    cur[j] = prev[j] || cur[j-1];
                }
                else if (p[i-1] == '?' || p[i-1] == s[j-1]) {
                    cur[j] = prev[j-1];
                }
                else {
                    cur[j] = false;
                }
            }
            
            prev = cur;
        }
        
        return prev[m];
    }
};