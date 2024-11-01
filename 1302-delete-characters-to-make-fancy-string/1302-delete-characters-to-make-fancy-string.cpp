class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        int cnt= 0;
        string res = "";
        res += s[0];

        for(int i=1; i<n; i++){
            if(s[i]!=s[i-1]){
                res+=s[i];
                cnt=0;
            }
            if(cnt >= 1 && s[i]==s[i-1]){
                cnt++;
                continue;
            }
            else if(s[i]==s[i-1]){
                cnt++;
                res+=s[i];
            }
            else{
                cnt = 0;
            }
            
        }
        return res;
    }
};