class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;
        vector<long long> cumulativeSum(n,0);

        int result = INT_MAX;

        int j = 0;

        while(j<n){
            if(j==0)cumulativeSum[0]=nums[0];
            else{
                cumulativeSum[j] = cumulativeSum[j-1]+nums[j];
            }

            if(cumulativeSum[j]>=k){
                result = min(result, j+1);
            }

            while(!deq.empty() && cumulativeSum[j]-cumulativeSum[deq.front()]>=k){
                result = min(result, j-deq.front());
                deq.pop_front();
            }
            while(!deq.empty() && cumulativeSum[j] <= cumulativeSum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            j++;

        }
        return result == INT_MAX?-1:result;
    }
};