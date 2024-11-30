class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> charSet;
        int res = 0;

        for (char c : s) {
            if (charSet.find(c) != charSet.end()) {
                charSet.erase(c);
                res += 2;
            } else {
                charSet.insert(c);
            }
        }

        if (!charSet.empty()) {
            res++;
        }

        return res;
    }
};