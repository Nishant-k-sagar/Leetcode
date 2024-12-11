class Solution {

    int binarySearch(vector<int> &nums, int target, int n){
        int left = 0;
        int right = n-1;

        while(left<=right){
            int mid = (left+right)/2;

            if(nums[mid]<=target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return right;
    }
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int maxBeauty = 0;

        for(int i=0; i<n; i++){
            int x = nums[i];
            int y = x + 2*k;

            int j = binarySearch(nums, y, n);

            maxBeauty = max(maxBeauty, j-i+1);
        }
        return maxBeauty;
    }
};