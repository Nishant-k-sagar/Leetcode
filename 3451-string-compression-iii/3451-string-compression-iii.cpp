class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int cnt = 1;
        char ch = word[0];
        int n = word.size();

        for(int i=1; i<=n; i++){
            if(word[i]==ch && cnt <9){
                cnt++;
            }
            else {
                res.push_back(cnt+'0');
                res.push_back(ch);
                cnt = 1;
            }
            ch = word[i];
        }
        return res;
    }
};