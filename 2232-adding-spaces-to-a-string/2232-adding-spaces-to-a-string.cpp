class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), m = spaces.size();
        string str(n+m, ' ');

        int  j=0;

        for(int i=0; i<n; i++){
            if(j<m && i==spaces[j]){
                str[i+j] = ' ';
                j++;
            }
            str[i+j] = s[i];
        }
        return str;
    }
};