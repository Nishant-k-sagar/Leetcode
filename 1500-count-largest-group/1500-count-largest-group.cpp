class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;

        int maxi = INT_MIN;
        while (n) {
            int dig = log10(n) + 1;
            // mp[dig]++;
            string s = to_string(n);
            int sum = 0;
            for(int i=0; i<dig; i++){
                sum+= s[i] - '0';
            }

            // cout<<sum<<" ";

            mp[sum]++;
            maxi = max(maxi, mp[sum]);
            n--;

        }

        // int maxi = INT_MIN;
        // for (auto& it : mp) {
        //     if (it.second >= maxi) {
        //         maxi = it.second;
        //     }
        // }
        
        int cnt = 0;

        for(auto &it : mp){
            if(it.second == maxi)cnt++;
        }
        return cnt;
    }
};