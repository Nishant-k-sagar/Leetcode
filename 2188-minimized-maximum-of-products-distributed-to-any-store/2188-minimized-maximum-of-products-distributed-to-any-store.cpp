class Solution {
public:

bool possibleToDistr(int x, vector<int> &q, int shops){
        for(int &p:q){
            shops -= (p+x-1)/x;
            if(shops<0)return false;
        }
        return true;
}

    int minimizedMaximum(int n, vector<int>& q) {
        int m = q.size();
        int l = 1;
        int r = *max_element(begin(q), end(q));

        int res = 0;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(possibleToDistr(mid, q, n)){
                res = mid;
                r = mid-1;
            }
             else {
                l = mid+1;
             }
        }
        return res;
    }
};