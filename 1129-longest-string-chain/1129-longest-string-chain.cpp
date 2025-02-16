class Solution {
public:
    bool possible(string &s1, string &s2) {
        if(s1.size() != s2.size() + 1) return false;

        int i = 0;
        int j = 0;

        while(i < s1.size()) {
            if(j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return (j == s2.size());
    }

    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);

        sort(arr.begin(), arr.end(), comp);

        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(possible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
            }

            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};
