class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.length();
        if(s[0]!=s[n-1])return false;

        for(int i=1; i<n-1; i++){
            if(s[i+1]==' '){
            if(s[i]!=s[i+2]) return false;
            }
        }
    return true;
    }
};