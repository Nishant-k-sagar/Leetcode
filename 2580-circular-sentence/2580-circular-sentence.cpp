class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n= sentence.length();

        char a = sentence[0];
        char b = sentence[n-1];
        char c = sentence[0];
        if(a!=b)return false;

        for(int i=1; i<n-1; i++){
            if(sentence[i+1]==' '){
                a = sentence[i];
                b = sentence[i+2];
            }
            if(a!=b)return false;
        }
    return true;
    }
};