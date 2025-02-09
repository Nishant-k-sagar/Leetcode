class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        // int n = num.size();

        for(int i=0; i<=(num+100)/2; i++){
            int temp = i;
            string s = to_string(temp);
            reverse(s.begin(), s.end());

            if(temp + stoi(s)==num)return true;
        }
        return false;
    }
};