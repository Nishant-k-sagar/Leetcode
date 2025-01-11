class Solution {
public:

    long long calTotH(vector<int>& v, int speed) {
        long long totH = 0;
        for (int i = 0; i < v.size(); i++) {
            totH += (v[i] + speed - 1) / speed;
        }
        return totH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totH = calTotH(piles, mid);
            
            if (totH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;

    }
};
