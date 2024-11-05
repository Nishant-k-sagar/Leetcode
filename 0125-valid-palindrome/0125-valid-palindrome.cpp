class Solution {
public:
    bool isPalindrome(string s) {
        string snew;
        for (char c : s) {
            if (isalnum(c)) { 
                snew.push_back(tolower(c)); 
            }
        }

        string r = snew;
        reverse(r.begin(), r.end());
        return snew == r;
    }
};
