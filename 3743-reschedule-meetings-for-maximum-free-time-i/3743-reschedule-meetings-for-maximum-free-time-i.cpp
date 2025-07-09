class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), res = 0, dur = 0;
        for (int i = 0; i < n; i++) {
            dur += endTime[i] - startTime[i];
            if (i >= k - 1) {
                int left;
                if (i - k < 0) {
                    left = 0;
                } else {
                    left = endTime[i - k];
                }
                int right;
                if (i == n - 1) {
                    right = eventTime;
                } else {
                    right = startTime[i + 1];
                }
                if (right - left - dur > res) {
                    res = right - left - dur;
                }
                dur -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }
        return res;
    }
};
