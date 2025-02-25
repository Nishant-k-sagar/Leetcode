class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        if(n==0)return 0;

        int left = 0;
        int right = 0;

        vector<int> hash(256, -1);
        // for(int i=0; i<256; i++){
        //     hash[i] = -1
        // }
        int maxi = INT_MIN;

        while(right<n){
            if(hash[s[right]]>=left){
                left = hash[s[right]]+1;
            }

            hash[s[right]] = right;
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};