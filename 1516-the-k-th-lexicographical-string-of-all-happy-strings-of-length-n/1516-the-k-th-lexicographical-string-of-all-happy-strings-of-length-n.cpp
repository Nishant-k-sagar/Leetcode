class Solution {
public:
    void solve(int n, string &cur, vector<string> & res){
        if(cur.length() == n){
            res.push_back(cur);
            return ;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!cur.empty() && cur.back() == ch)continue;

            cur.push_back(ch);

            solve(n, cur, res);

            cur.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string cur = "";

        vector<string> res;

        solve(n, cur, res);

        if(res.size() < k){
            return "";
        }

        return res[k-1];
    }
};