class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        bool flag = true;
        if (i < n && s[i] == '-') {
            flag = false;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }

        long long ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans*1LL*10 + (s[i] - '0');
            if (ans > INT_MAX) {
            return flag ? INT_MAX : INT_MIN;
        }
            i++;
        }

        

        return flag ? ans : -ans;
    }
};
