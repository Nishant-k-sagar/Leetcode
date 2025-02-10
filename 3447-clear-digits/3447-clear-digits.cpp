class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();

        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<n; i++){
            if(s[i] <='9' && s[i]>='0'){
                st.pop();
            }
            else st.push(s[i]);    
        }
        string res = "";

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};