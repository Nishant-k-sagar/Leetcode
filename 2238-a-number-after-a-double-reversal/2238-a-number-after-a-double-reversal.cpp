class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0)return true;
        if(num%10!=0)return true;
        else return false;
    }
};