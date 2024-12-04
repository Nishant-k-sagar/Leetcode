class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int i1=0, i2=0;
        while(i1<n){
            if(int(str1[i1])==int(str2[i2]) || int(str1[i1])+1==int(str2[i2])||(str1[i1]=='z' && str2[i2]=='a')){
                i1++;
                i2++;
            }
            else{
                i1++;
            }
        }
        return (i2==m)?1:0;
    }
};