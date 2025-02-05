class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        string temp1(s1.begin(), s1.end());
        string temp2(s2.begin(), s2.end());

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        if(temp1!=temp2)return false;

        int cnt = 0;

        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i])cnt++;
        }

        if(cnt < 3 && cnt%2==0)return true;
        else return false;
    }
};