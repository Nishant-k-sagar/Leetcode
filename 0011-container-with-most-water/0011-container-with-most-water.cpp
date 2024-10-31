class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1;

        int water = 0;
        int left = 0;
        int right = n;

        while(left<right){
            int width = right - left;
            int calc_water = width * min(height[left], height[right]);
            water = max(calc_water, water);
            if(height[left]<=height[right])left++;
            else right--;
        }
        return water;
    }
};