class Solution {
public:
    #define ll long long
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        ll res = 0;

        for(ll i = 0; i<n; i++){
            nums[i] = nums[i]-i;
        }

        unordered_map<ll, ll> mp;

        // mp[nums[0]] = 1;

        for(ll j=0; j<n; j++){
            // mp[nums[j]]++;
            ll cntNumsj = mp[nums[j]]++;
            ll totNumsBeforej = j;

            ll badPairs = totNumsBeforej - cntNumsj;

            res+= badPairs;

        }
        return res;
        
    }
};