class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        
         long ans = 0;
        vector<pair<int, int>>sorted(n);

        for(int i=0; i<n; i++){
            sorted[i] = make_pair(nums[i], i);
        }

        sort(sorted.begin(), sorted.end());

        vector<bool>marked(n, false);

        for(int i=0; i<n; i++){
            int num = sorted[i].first;
            int idx = sorted[i].second;

            if(!marked[idx]){
                ans = ans+num;
                marked[idx] = true;

                if(idx>=1){
                    marked[idx-1] = true;
                }
                if(idx<=n-1){
                    marked[idx+1] = true;
                }
            }
        }
        return ans;
    }
};