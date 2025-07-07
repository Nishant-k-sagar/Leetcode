class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int rad = 0;

        for(int h : houses){
            // auto it = lower_bound(heaters.begin(), heaters.end(), h);

            // int dist1 = INT_MAX;

            // if(it != heaters.end()){
            //     dist1 = abs(*it - h);
            // }

            // int dist2 = INT_MAX;
            // if(it != heaters.begin()){
            //     dist2 = abs(*(it - 1) - h);
            // }

            // int mini = min(dist1, dist2);
            // r = max(r, mini);

            int l = 0;
            int r = heaters.size()-1;
            int mini = INT_MAX;

            while(l <= r){
                int mid = l + (r - l)/2;

                if(heaters[mid] == h){
                    mini = 0;
                    break;
                }
                else if(heaters[mid] < h){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }

            if(l < heaters.size()){
                mini = min(mini, abs(heaters[l] - h));
            }
            if(r >= 0){
                mini = min(mini, abs(heaters[r] - h));
            }
            rad = max(rad, mini);
        }
        return rad;
    }
};