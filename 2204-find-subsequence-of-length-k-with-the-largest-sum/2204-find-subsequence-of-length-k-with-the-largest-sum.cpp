class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        for(int i =0; i<n; i++){
            vec.push_back({i, nums[i]});
        }
        sort(vec.begin(), vec.end(), [&](auto x1, auto x2){
            return x1.second > x2.second;
        });
        
        sort(vec.begin(), vec.begin() + k);
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(vec[i].second);
        }
        return res;
    }
};