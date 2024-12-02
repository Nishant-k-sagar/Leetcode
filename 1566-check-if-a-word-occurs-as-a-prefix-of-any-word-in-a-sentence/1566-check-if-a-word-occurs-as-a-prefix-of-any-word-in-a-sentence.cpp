#include <sstream>
#include <vector>

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        string word;
        int wordIndex = 1;

        while (stream >> word) {
            if (word.substr(0, searchWord.length()) == searchWord) {
                return wordIndex;
            }
            wordIndex++;
        }

        return -1;
    }
};
