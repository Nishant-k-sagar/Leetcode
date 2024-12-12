class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        int left = 0;
        int maxi = 0;

        for(int right = 0; right<n; right++){
            if(mp.find(s[right])!=mp.end() && mp[s[right]] >= left){
                left = mp[s[right]]+1;
            }
            mp[s[right]] = right;

            maxi = max(maxi, right-left+1);
        }
        return maxi;
    }
};