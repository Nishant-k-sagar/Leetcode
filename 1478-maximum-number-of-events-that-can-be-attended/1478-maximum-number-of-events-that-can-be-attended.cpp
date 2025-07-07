class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int day = 1, i=0, n = events.size(), res = 0;

        int prev = 0;
        for(auto e : events){
            prev = max(prev, e[1]);
        }

        for(int day = 1; day<= prev; day++){
            while(i<n and events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                res++;
            }
        }
        return res;
    }
};