class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int ans = 0;
        char curr = '0';

        for(char ch : target){
            if(ch != curr){
                ans++;
                curr = ch;
            }
        }
        return ans;
    }
};