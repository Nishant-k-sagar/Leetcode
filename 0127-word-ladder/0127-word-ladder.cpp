class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == targetWord) return steps; // Found the target word
            
            for (int i = 0; i < word.size(); i++) {
                char original = word[i]; // Restores the i-th letter in word after it gets changed
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.find(word) != st.end()) { // Valid transformation
                        st.erase(word); // Remove word to avoid revisiting
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; // Restore original character
            }
        }
        return 0; // not found
    }
};