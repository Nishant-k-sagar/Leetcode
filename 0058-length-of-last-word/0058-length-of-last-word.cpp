class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int n = s.size();

        for(int i=n-1; i>=0; i--){
            if(cnt == 0 && s[i]==' '){
                continue;
            }
            else if(s[i] != ' '){
                cnt++;
            }
            else
            break;
        }
        return cnt;
    }
};