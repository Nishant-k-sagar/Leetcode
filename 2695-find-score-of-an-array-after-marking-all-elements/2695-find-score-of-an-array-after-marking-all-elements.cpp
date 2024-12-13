class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;

        vector<bool> marked(n, false);

        auto cmp = [](pair<int, int> &pair1, pair<int, int> &pair2){
            if(pair1.first != pair2.first)return pair1.first > pair2.first;
            return pair1.second> pair2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>heap(cmp);

        for(int i=0; i<n; i++){
            heap.push(make_pair(nums[i], i));
        }

        while(!heap.empty()){
            pair<int, int> ele = heap.top();

            heap.pop();

            int num = ele.first;
            int idx = ele.second;

            if(!marked[idx]){
                ans+=num;
                marked[idx] = true;

                if(idx-1>=0){
                    marked[idx-1] = true;
                }
                if(idx+1<n){
                    marked[idx+1] = true;
                }
            }
        }
        return ans;
    }
};