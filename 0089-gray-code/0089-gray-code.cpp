class Solution {

    vector<string> solve(int n){
        if(n==1){
            return {"0", "1"};
        }

        vector<string> ans;

        vector<string> temp = solve(n-1);
        for(int i=0; i<temp.size(); i++){
            ans.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back("1"+temp[i]);
        }
    return ans;
    }
public:
    vector<int> grayCode(int n) {
        vector<string> res = solve(n);

        vector<int> ans;

        for(auto i:res){
            ans.push_back(stoi(i, 0, 2));
        }
            return ans;
    }
};