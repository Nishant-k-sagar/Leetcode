class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0, j = needle.size(); j<=haystack.size(); i++, j++){
            if(haystack.substr(i,needle.length())==needle){
                return i;
            }
        }
    return -1;
    }
};