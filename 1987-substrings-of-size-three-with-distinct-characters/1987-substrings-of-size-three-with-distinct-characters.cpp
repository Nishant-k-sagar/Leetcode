class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();

        int left = 0;
        int right = 0;
        int cnt = 0;

        while(right < n){
            right++;
            set<int> st;
            if(right - left == 3){
                for(int i = left; i<right; i++){
                    st.insert(s[i]);
                }

                if(st.size() == 3)cnt++;
                left++;
            }
        }
        return cnt;
    }
};