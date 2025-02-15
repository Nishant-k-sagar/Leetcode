#include <string>
using namespace std;

class Solution {
public:
    bool canPartition(string str, int i, int sum) {
        if (i == str.length()) return sum == 0;
        for (int len = 1; len <= str.length() - i; len++) {
            int part = stoi(str.substr(i, len));
            if (canPartition(str, i + len, sum - part)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int punishmentSum = 0;

        for (int i = 1; i <= n; i++) {
            int square = i * i;
            if (canPartition(to_string(square), 0, i)) {
                punishmentSum += square;
            }
        }
        return punishmentSum;
    }
};
