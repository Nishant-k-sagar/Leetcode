class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int r = 0;

        for(int h : houses){
            auto it = lower_bound(heaters.begin(), heaters.end(), h);

            int dist1 = INT_MAX;

            if(it != heaters.end()){
                dist1 = abs(*it - h);
            }

            int dist2 = INT_MAX;
            if(it != heaters.begin()){
                dist2 = abs(*(it - 1) - h);
            }

            int mini = min(dist1, dist2);
            r = max(r, mini);
        }
        return r;
    }
};