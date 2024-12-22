class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h,
                                        vector<vector<int>>& q) {
        vector<vector<vector<int>>> storeq(h.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        vector<int> ans(q.size(), -1);

        for (int currq = 0; currq < q.size(); currq++) {
            int a = q[currq][0], b = q[currq][1];
            if (a < b && h[a] < h[b]) {
                ans[currq] = b;
            } else if (a > b && h[a] > h[b]) {
                ans[currq] = a;
            } else if (a == b) {
                ans[currq] = a;
            } else {
                storeq[max(a, b)].push_back(
                    {max(h[a], h[b]), currq});
            }
        }

        for (int idx = 0; idx < h.size(); idx++) {
            while (!pq.empty() && pq.top()[0] < h[idx]) {
                ans[pq.top()[1]] = idx;
                pq.pop();
            }
            for (auto& ele : storeq[idx]) {
                pq.push(ele);
            }
        }
        return ans;
    }
};