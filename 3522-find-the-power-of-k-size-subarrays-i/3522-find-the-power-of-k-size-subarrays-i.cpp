class Solution {
public:

    bool checker(vector<int> &v){
        int m = v.size();
        for(int i=1; i<m; i++){
            if(v[i-1]+1!=v[i])return false;
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res;

        for(int i=0; i<=n-k; i++){
            vector<int> subarr(nums.begin()+i, nums.begin()+k+i);

            if(checker(subarr)){
                res.push_back(*max_element(subarr.begin(), subarr.end()));
            }
            else{
                res.push_back(-1);
            }
        }
        return res;
    }
};