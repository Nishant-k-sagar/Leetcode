class Solution {
    void skipspace(string &str, int &n, int &pos) {
        while (pos < n && str[pos] == '_') pos++;
    }

public:
    bool canChange(string s, string t) {
        int n = s.size();

        int i = 0, j = 0;

        int lim_idx = -1;

        while (i < n) {
            skipspace(s, n, i);
            skipspace(t, n, j);

            if (i == n && j == n) return true;
            if (s[i] != t[j]) return false;

            if (s[i] == 'L' && (j <= lim_idx || j > i)) {
                return false;
            }
            else if (s[i] == 'R' && i > j) {
                return false;
            }
            lim_idx = j;
            i++;
            j++;
        }
        skipspace(s, n, i);
        skipspace(t, n, j);
        return i == n && j == n;
    }
};
