class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n  = nums.size();
        int m = queries.size();

        vector<int> hashvec(n,0);
        vector<bool> ans(m, false);


        hashvec[0] = 0;

        for(int i=1; i<n; i++){
            if(nums[i]%2==nums[i-1]%2){
                hashvec[i] = hashvec[i-1]+1;
            }
            else{
                hashvec[i] = hashvec[i-1];
            }
        }

//         for (int i = 0; i < n; ++i) {
//     cout << "hashvec[" << i << "] = " << hashvec[i] << endl;
// }



        for(int i = 0; i<m ; i++){
            int from = queries[i][0];
            int to = queries[i][1];

            bool flag = hashvec[to] - hashvec[from] == 0;
            ans[i] = flag;
        }
        
        return ans;
    }
};
