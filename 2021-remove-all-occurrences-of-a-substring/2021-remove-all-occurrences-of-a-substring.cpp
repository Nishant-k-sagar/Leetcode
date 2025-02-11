class Solution {
public:
    bool checker(stack<char> &st, string &part, int m){
        stack<char> temp = st;

        for(int i = m-1; i>=0; i--){
            if(temp.top()!=part[i]){
                return false;
            }
            temp.pop();
        }   
        return true;
    }

    string removeOccurrences(string s, string part) {
       stack<char>st;

       int n = s.length();
       int m = part.length();

       for(int i=0; i<n; i++){
        st.push(s[i]);

        if(st.size()>= m && checker(st, part, m)==true){
            for(int j = 0; j<m; j++){
                st.pop();
            }
        }
       }
       string res = "";

       while(!st.empty()){
        res.push_back(st.top());
        st.pop();
       }

       reverse(res.begin(), res.end());
       return res;
    }
};