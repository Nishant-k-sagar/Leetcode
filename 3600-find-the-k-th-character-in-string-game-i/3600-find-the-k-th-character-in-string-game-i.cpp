class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.length()<=k){
            string temp = "";
            for(char c : word){
                temp += (c == 'z')? 'a' : c+1;
            }
            word = word+temp;
        }
        return word[k-1];
    }
};