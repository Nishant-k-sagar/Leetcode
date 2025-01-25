class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int currGrp = 0;
        unordered_map<int, int> mpp;
        mpp.insert(pair<int, int>(sorted[0], currGrp));

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(
            pair<int, list<int>>(currGrp, list<int>(1, sorted[0])));

        for (int i = 1; i < nums.size(); i++) {
            if (abs(sorted[i] - sorted[i - 1]) > limit) {
                currGrp++;
            }

            mpp.insert(pair<int, int>(sorted[i], currGrp));

            if (groupToList.find(currGrp) == groupToList.end()) {
                groupToList[currGrp] = list<int>();
            }
            groupToList[currGrp].push_back(sorted[i]);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = mpp[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};