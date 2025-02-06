class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int len = nums.size();

        vector<int> pairProd;

        int ans = 0;

   
        for (int idx1 = 0; idx1 < len; idx1++) {
            for (int idx2 = idx1 + 1; idx2 < len;
                 idx2++) {
                pairProd.push_back(nums[idx1] * nums[idx2]);
            }
        }

        sort(pairProd.begin(), pairProd.end());

        int lastProductSeen = -1;
        int cnt = 0;


        for (int productIndex = 0; productIndex < pairProd.size();
             productIndex++) {
            if (pairProd[productIndex] == lastProductSeen) {

                cnt++;
            } else {

                int pairsOfEqualProduct =
                    (cnt - 1) * cnt / 2;

                ans += 8 * pairsOfEqualProduct;

                lastProductSeen = pairProd[productIndex];
                cnt = 1;
            }
        }

        
        int pairsOfEqualProduct = (cnt - 1) * cnt / 2;
        ans += 8 * pairsOfEqualProduct;

        return ans;
    }
};