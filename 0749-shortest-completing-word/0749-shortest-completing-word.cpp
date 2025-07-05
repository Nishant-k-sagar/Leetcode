class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> platemap;
        for(char ch : licensePlate){
            if(isalpha(ch)){
                platemap[tolower(ch)]++;
            }
        }

        string result = "";
        for(string word : words){
            unordered_map<char, int> wordmap;
            for(char ch : word){
                wordmap[tolower(ch)]++;
            }

            bool checker = true;
            for(auto &it : platemap){
                if(wordmap[it.first] < it.second){
                    checker = false;
                    break;
                }
            }

            if(checker){
                if(result == "" || word.length() < result.length()){
                    result = word;
                }
            }
        }
        return result;
    }
};