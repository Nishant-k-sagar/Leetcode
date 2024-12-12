class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int maxi = 0;

        unordered_set<char> charSet;

        for(int i=0; i<n; i++){
            while(charSet.find(s[i])!=charSet.end()){
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[i]);
            maxi = max(maxi, i-left+1);
        }
        return maxi;
    }
};