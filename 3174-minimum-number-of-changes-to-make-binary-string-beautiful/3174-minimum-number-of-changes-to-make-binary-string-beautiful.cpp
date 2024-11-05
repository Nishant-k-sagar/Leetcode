class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int cnt = 0;
        int i=1;
        if(n%2!=0)return false;
        while(i<n){
            if(s[i]!=s[i-1]){
                cnt++;
            }
            i=i+2;
        }
        return cnt;
    }
};