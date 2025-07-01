class Solution {
private:
    bool chk(string &s1, int i, string &s2, int j, string &s3, int k){
        if(k == s3.size()){
            if((i == s1.size()) && (j == s2.size()))return true;
            else return false;
        }

        bool matchs1 = false, matchs2 = false;
        if( i < s1.size() && s1[i] == s3[k]){
            matchs1 = chk(s1, i+1, s2, j, s3, k+1);
        }
        if(j < s2.size() && s2[j] == s3[k]){
            matchs2 = chk(s1, i, s2, j+1, s3, k+1);
        }
        return matchs1 || matchs2;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        return chk(s1, 0, s2, 0, s3, 0);
    }
};