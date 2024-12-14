class Solution {

    void solve(int n, int idx, string &digits, string &temp, vector<string>&ans, unordered_map<char, string> &mp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }

        char ch = digits[idx];
        for(auto it: mp[ch]){
            temp+=it;
            solve(n, idx+1, digits, temp, ans, mp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();

        if(n==0)return ans;
        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp;
        solve(n, 0, digits, temp, ans, mp);
        return ans;
    }
};