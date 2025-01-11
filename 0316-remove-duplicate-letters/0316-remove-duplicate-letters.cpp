class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();

        string result = "";
        vector<bool> taken(26, false);
        vector<int> LastIdx(26);

        for(int i=0; i<n; i++){
            char ch = s[i];
            LastIdx[ch - 'a'] = i;
        }

        for(int i=0; i<n; i++){
            char ch = s[i];
            int idx = ch - 'a';

            if(taken[idx]==true)continue;

            while(result.length()> 0 && result.back()>ch && LastIdx[result.back()- 'a'] > i){
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[idx] = true;
        }        
        return result;
    }
};