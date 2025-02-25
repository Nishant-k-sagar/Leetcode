class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& t) {
        int count = s.size(), c = 0, sq = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 0)
                c++;
            else
                sq++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == 0) {
                if (c > 0) {
                    count--;
                    c--;
                } else {
                    return count;
                }
            } else {
                if (sq > 0) {
                    count--;
                    sq--;
                } else {
                    return count;
                }
            }
        }
        return count;
    }
};
