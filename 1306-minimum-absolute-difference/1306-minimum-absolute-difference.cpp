class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> vec;
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int mini = INT_MAX;

        for(int i=1; i<n; i++){
            int diff = arr[i] - arr[i-1];
            mini = min(mini, diff);
        }

        for(int i=1; i<n; i++){
            int diff = arr[i] - arr[i-1];
            vector<int> temp;
            if(diff == mini){
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                vec.push_back(temp);
            }
        }
        return vec;
    }
};
