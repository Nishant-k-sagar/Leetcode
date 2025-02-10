class Solution {
public:
    #define ll long long
    int maxScore(vector<int>& nums) {
        ll n = nums.size();

        sort(nums.begin(), nums.end(), greater<int>());

        vector<ll> arr(n);

        arr[0] = nums[0];
        for(ll i=1; i<n; i++){
            arr[i] = arr[i-1] + nums[i];
        }

        ll cnt = 0;
        for(ll i=0; i<n; i++){
            if(arr[i]>0)cnt++;
        }
        return cnt;
    }
};