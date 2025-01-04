class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<pair<int, int>> indices(26, {-1, -1});
        int ans = 0;

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';

            if(indices[idx].first == -1) {
                indices[idx].first = i;
            }
            indices[idx].second = i;
        }

        
        for(int i = 0; i < 26; i++) {
            int lt_idx = indices[i].first;
            int rt_idx = indices[i].second;

            if(lt_idx == -1) continue;

            set<char> st;

            for(int j = lt_idx + 1; j <= rt_idx - 1; j++) {
                st.insert(s[j]);
            }

            ans += st.size();
        }

        return ans;
    }
};
