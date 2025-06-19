class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;

        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(st.empty()){
                return false;
            }
            else{
                char ch = st.top();
                // st.top();
                if((ch == '(' && s[i] == ')') || (ch == '{' && s[i] == '}') || (ch == '[' && s[i] == ']')){
                    st.pop();
                }
                else return false;
            }
        }
            return st.empty();
    }
};