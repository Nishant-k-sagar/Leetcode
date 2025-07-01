class Solution {
public:
    int possibleStringCount(string word) {
        int n =word.length();
        int totCnt= 1;
        
        int i = 0;
        while (i <n) {
            char currChar =word[i];
            int cnt = 0;
            
            while (i < n&& word[i] == currChar) {
                ++cnt;
                ++i;
            }
            
            totCnt += cnt - 1;
        }
        
        return totCnt;
    }
};
