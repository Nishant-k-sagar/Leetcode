class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n= nums.size();

        vector<pair<int, int>>vec;

        for(int i=0;i<n; i++){
            vec.push_back({nums[i]-k, nums[i]+k});
        }

        sort(vec.begin(), vec.end());

        deque<int> deq;

        int maxBeauty = 0;

        for(pair<int, int> &p : vec){
            while(!deq.empty() && deq.front()<p.first){
                deq.pop_front();
            }

            deq.push_back(p.second);

            maxBeauty = max(maxBeauty, (int)deq.size());
        }
        return maxBeauty;
    }
};