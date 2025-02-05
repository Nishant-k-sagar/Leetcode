class Solution {
public:
    int distributeCandies(vector<int>& ct) {
        int n = ct.size();

        sort(ct.begin(), ct.end());

        int half = n/2;

        int cntUniq = 1;

        for(int i=1; i<n; i++){
            if(ct[i]!=ct[i-1])cntUniq++;
        }

        if(cntUniq<half)return cntUniq;
        else return half;
    }
};