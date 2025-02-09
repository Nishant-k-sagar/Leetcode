class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.length();

        float cnt = count(s.begin(), s.end(), letter);

        return ((cnt*1.0)/n)*100; 
    }
};