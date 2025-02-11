class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int len = part.length();
            int idx = s.find(part);
            if(idx==-1){
                break;
            }
            s.erase(idx, len);
        }
        return s;
    }
};