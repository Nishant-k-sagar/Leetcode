class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mpp1, mpp2, mpp3;

        for (int num : nums1) mpp1[num]++;
        for (int num : nums2) mpp2[num]++;
        for (int num : nums3) mpp3[num++];

        vector<int> ans;
        unordered_set<int> seen;

        for (auto it : mpp1) {
            int num = it.first;
            if ((mpp2.count(num) || mpp3.count(num)) && seen.count(num) == 0) {
                ans.push_back(num);
                seen.insert(num);
            }
        }

        for (auto it : mpp2) {
            int num = it.first;
            if (mpp3.count(num) && !mpp1.count(num) && seen.count(num) == 0) {
                ans.push_back(num);
                seen.insert(num);
            }
        }

        return ans;
    }
};