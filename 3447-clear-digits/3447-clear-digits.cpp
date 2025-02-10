class Solution {
public:
    string clearDigits(string s) {
        int idx = 0;

        while(idx<s.size()){
            if(isdigit(s[idx])){
                s.erase(idx,1);
                if(idx>0){
                    s.erase(idx-1, 1);
                    idx--;
                }
            }
            else idx++;
        }
        return s;
    }
};