class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int right = n-1;
        while(right>0 && arr[right]>=arr[right-1]){
            right--;
        }

        int left = 0;

        int res = right;

        while( left <right && (left == 0 || arr[left]>=arr[left-1])){
            while(right<n && arr[left]>arr[right]){
                right++;
            }

            res = min(res,right-left-1);
            left++;
        }
        return res;

    }
};