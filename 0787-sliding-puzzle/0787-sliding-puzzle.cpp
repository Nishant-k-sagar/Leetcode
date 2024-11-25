class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                          {0, 4}, {1, 3, 5}, {2, 4}};

        string tar = "123450";
        string startState;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                startState += to_string(board[i][j]);
            }
        }

        unordered_set<string> visited;
        queue<string> que;
        que.push(startState);
        visited.insert(startState);

        int moves = 0;

        while (!que.empty()) {
            int size = que.size();
            while (size-- > 0) {
                string currState = que.front();
                que.pop();


                if (currState == tar) {
                    return moves;
                }

                int zeroPos = currState.find('0');
                for (int newPos : directions[zeroPos]) {
                    string nextState = currState;
                    swap(nextState[zeroPos], nextState[newPos]);


                    if (visited.count(nextState)) continue;

                    visited.insert(nextState);
                    que.push(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};