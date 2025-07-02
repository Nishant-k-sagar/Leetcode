class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int n = words.size();
        vector<string> arr = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            int sz = words[i].size();
            for (int j = 0; j < 3; j++) {
                bool flag = true;
                for (int k = 0; k < sz; k++) {
                    if(arr[j].find(tolower(words[i][k])) == string :: npos){
                        flag = false;
                    }
                }
                if(flag){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};