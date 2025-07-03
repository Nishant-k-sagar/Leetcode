class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2 == 0){
            int lim = n - 1;
            for(int i= -lim; i<= lim; i+=2){
                ans.push_back(i);
            }
        }
        else {
            int lim = n / 2;
            for(int i = -lim; i<= lim; i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};