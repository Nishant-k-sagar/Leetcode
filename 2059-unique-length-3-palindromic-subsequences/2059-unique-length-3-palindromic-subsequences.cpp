class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        unordered_set<char>letters(s.begin(), s.end());

        int ans = 0;

        for(auto it:letters){
            int lt_idx = -1;
            int rt_idx = -1;

            for(int i=0; i<n; i++){
                if(s[i] == it){
                    if(lt_idx == -1){
                        lt_idx = i;
                    }
                    rt_idx = i;
                }
            }
            unordered_set<char> st;

            for(int i=lt_idx+1; i<=rt_idx-1; i++){
                st.insert(s[i]);
            }
            ans +=st.size();
        }
        return ans;
    }
};