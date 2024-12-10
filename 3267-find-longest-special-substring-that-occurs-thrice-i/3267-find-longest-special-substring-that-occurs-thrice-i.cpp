class Solution {
public:
    int maximumLength(string s) {
        map<string, int> mp;

        int n = s.length();
        for(int i=0; i<n; i++){
            string scurr;
            for(int j = i; j<n; j++){
                if(scurr.empty() or scurr.back() == s[j]){
                    scurr.push_back(s[j]);
                    mp[scurr]++;
                }
                else break;
            }
        }

        int ans = 0;

        for(auto i : mp){
            string str = i.first;
            if(i.second >= 3 && str.length()>ans)ans = str.length();
        }

        if(ans == 0)return -1;
        return ans;
    }
};