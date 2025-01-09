class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = words.size();

        int ans = 0;

        for(int i=0; i<n; i++){
            int idx = s.find(words[i]);
            if(idx==0)ans++;
        }
        return ans;
    }
};