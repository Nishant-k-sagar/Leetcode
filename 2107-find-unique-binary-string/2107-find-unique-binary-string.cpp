class Solution {
public:
    int n;
    unordered_set<string> st;

    string rec(string cur){
        if(cur.size() == n){
                if(st.find(cur) == st.end()){
                    return cur;
            }

            return "";

        }

        string addZero = rec(cur + "0");

        if(addZero.size() > 0) {
            return addZero;
        }

        return rec(cur + "1");
    }

    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        st.clear();
        for(string s : nums){
            st.insert(s);
        }

        return rec("");
    }
};