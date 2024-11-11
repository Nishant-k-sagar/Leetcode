class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int diff;
            if(i==0)diff = nums[0];
            else{
                diff = (nums[i]-nums[i-1]);
            }

            if(diff<=0)return false;

            int Lprime =  0;
            for(int i = diff-1; i>=2; i--){
                if(checker(i)){
                    Lprime = i;
                    break;
                }
            }

            nums[i] = nums[i]-Lprime;
        }
        return 1;
    }

public:
    bool checker(int x){
        for(int i = 2; i<=sqrt(x); i++){
            if(x%i==0)return false;
        }
        return true;
    }
};