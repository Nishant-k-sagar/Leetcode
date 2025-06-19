class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        
        stack<int> st;

        for(int i=0; i<n; i++){
            st.push(s[i]);
        }

        for(int i=0; i<n; i++){
            s[i] = st.top();
            st.pop();
        }
        // return s;
    }
};