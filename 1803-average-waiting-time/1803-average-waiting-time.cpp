class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitTime = 0;
        int n = customers.size();

        int lastTime = customers[0][0];
        for(int i=0; i<n; i++){
            int started = max(customers[i][0], lastTime);
            int finished = started + customers[i][1];
            waitTime += finished - customers[i][0];
            lastTime = finished;
        }

        return (waitTime / n);
    }
};