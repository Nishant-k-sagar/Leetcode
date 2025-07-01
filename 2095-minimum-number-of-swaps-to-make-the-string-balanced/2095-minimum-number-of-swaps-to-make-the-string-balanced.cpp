class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int maxImbalance = 0;

        for(char ch : s){
            if(ch == '['){
                balance++;
            }
            else 
            {
                balance--;
                if(-balance > maxImbalance){
                    maxImbalance = -balance;
                }
            }
        }
        return (maxImbalance+1)/2;
    }
};