class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n, -1);

        for(int i=0; i<n; i++){
            int tar = nums1[i];
            for(int j=0; j<m; j++){
                if(nums2[j] == tar){
                    for(int k = j+1; k<m; k++){
                        if(nums2[k] > tar){
                            res[i] = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return res;
    }
};