class Solution {
public:
    bool isPrefixAndSuffix(string &str1, string &str2) {
        int siz1 = str1.length();
        int siz2 = str2.length();

        if (siz1 > siz2) return false;

        if (str2.substr(0, siz1) != str1) return false;

        if (str2.substr(siz2 - siz1) != str1) return false;

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string s1 = words[i];
                string s2 = words[j];

                if (isPrefixAndSuffix(s1, s2)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
