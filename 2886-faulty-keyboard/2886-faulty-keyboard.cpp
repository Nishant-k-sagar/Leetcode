class Solution {
public:
    string finalString(string s) {
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == 'i'){
                reverse(s.begin(), s.begin() + i);
            }
        }
        string ans;
        for(int i=0; i<n; i++){
            if(s[i] != 'i')ans+=s[i];
        }
        return ans;
    }
};