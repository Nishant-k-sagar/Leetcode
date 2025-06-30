class Solution {
    vector<vector<int>> chkdp;
    // vector<vector<string>> recdp;
    vector<vector<pair<int, int>>> recdp;
    private:
    //check if the string is palindrome
    bool chk(string &s, int i, int j){
        if(i >= j) return true;
        if(chkdp[i][j] != -1)return chkdp[i][j];
        if(s[i] != s[j]) return chkdp[i][j] = 0;
        else chkdp[i][j] = chk(s, i+1, j-1);
        return chkdp[i][j];
    }

    private:
    pair<int, int> recursion(string &s, int i, int j){
        if(i>j) return {-1, 0};
        if(i == j) return {i, 1};
        if(recdp[i][j].first != -1) return recdp[i][j];

        if(chk(s, i, j)){
            recdp[i][j] = {i, j-i+1};
            return recdp[i][j];
        }

        auto left = recursion(s,  i+1, j);
        auto right = recursion(s, i, j-1);

        if(left.second >= right.second) recdp[i][j] = left;
        else recdp[i][j] = right;
        return recdp[i][j];
    }

    // private:
    // string recursion(string &s, int i, int j){
    //     if(i>j) return "";
    //     if(i == j)return string(1, s[i]);

    //     if(!recdp[i][j].empty()) return recdp[i][j];

    //     if(chk(s, i, j)){
    //         recdp[i][j] = s.substr(i, j-i+1);
    //         return recdp[i][j];
    //     }

    //     string left = recursion(s, i+1, j);
    //     string right = recursion(s, i, j-1);

    //     recdp[i][j] = (left.length() >= right.length()) ? left : right;

    //     return recdp[i][j];
    // }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        chkdp.assign(n, vector<int> (n, -1));
        recdp.assign(n, vector<pair<int, int>> (n, {-1, 0}));

        auto ans = recursion(s, 0, n-1);
        if(ans.first == -1) return "";
        return s.substr(ans.first, ans.second);
    }
};