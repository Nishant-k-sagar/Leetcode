class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> temp(n, 0);
        if(k==0)return temp;

        for(int i=0; i<n; i++){
            if(k>0){
                for(int j=i+1; j<i+k+1; j++){
                    temp[i] += code[j%n];
                }
            }
            else{
                for(int j = i-abs(k); j<i; j++){
                    temp[i] += code[(j+n)%n];
                }
            }
        }
        return temp;
    }
};