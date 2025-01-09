class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int siz = pref.length();

        int n = words.size();

        int cnt = 0;
        for(int i=0; i<n; i++){
            string s = words[i].substr(0, siz);
            if(s==pref)cnt++;
        }
        return cnt;
    }
};