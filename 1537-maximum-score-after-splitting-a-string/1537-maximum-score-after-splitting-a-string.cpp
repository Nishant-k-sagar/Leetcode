class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int cnt0 = count(s.begin(), s.begin() + i + 1, '0');
            int cnt1 = count(s.begin() + i + 1, s.end(), '1');
            ans = max(ans, cnt0 + cnt1);
        }
        return ans;
    }
};
