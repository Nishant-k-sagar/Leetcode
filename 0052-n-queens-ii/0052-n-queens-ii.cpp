class Solution {
public:
    int queens[10];

    bool possible(int row, int col) {
        for (int i = 0; i < row; i++) {
            int prow = i;
            int pcol = queens[i];

            if (pcol == col || abs(prow - row) == abs(pcol - col)) {
                return false;
            }
        }
        return true;
    }

    int rec(int row, int n) {
        if (row == n) {
            return 1;
        }

        int ans = 0;

        for (int col = 0; col < n; col++) {
            if (possible(row, col)) {
                queens[row] = col;  
                ans += rec(row + 1, n);
                queens[row] = -1;
            }
        }
        return ans;
    }

    int totalNQueens(int n) {
        memset(queens, -1, sizeof(queens));
        return rec(0, n);
    }
};
